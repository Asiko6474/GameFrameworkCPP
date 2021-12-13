#include "Actor.h"
#include "Transform2D.h"
#include <string.h>
#include "Collider.h"
#include "Component.h"

Actor::Actor()
{
    m_transform = new Transform2D(this);
}

Actor::~Actor()
{
    delete m_transform;
}


Actor::Actor(float x, float y, const char* name = "Actor")
{
    //Initialze default values
    m_transform = new Transform2D(this);
    m_transform->setLocalPosition({ x,y });
    m_name = name;
}

Component* Actor::getComponent(const char* componentName)
{
    //iterate through the component array
    for (int i = 0; i < m_componentCount; i++)
    {
        //return the component if the name is the same as the current component
        if (strcmp(m_component[i]->getName(), componentName) == 0)
        {
            return m_component[i];
        }
    }
    //return nullptr if the component is not in the list
	return nullptr;
}

Component* Actor::addComponent(Component* component)
{
    //return null if this component has na owner already
    Actor* owner = component->getOwner();
    if (owner)
        return nullptr;

    component->assignOwner(this);

    //create a new array with a size one greater than our old array
    Component** appendArray = new Component * [m_componentCount + 1];
    //copy the values from the old array to the new array
    for (int i = 0; i < m_componentCount; i++)
    {
        appendArray[i] = m_component[i];
    }
    //set the last value in the new array to be the actor we want to add
    appendArray[m_componentCount] = component;
    if (m_componentCount > 1)
        delete[] m_component;
    else if (m_componentCount == 1)
        delete m_component;


    //set the old array to hold the values of the new array
    m_component = appendArray;
    m_componentCount++;

    return component;
}

 bool Actor::removeComponent(Component* name)
{
    if (!name)
        return false;

    bool componentRemoved = false;
    //create a new array with a size one greater than our old array
    Component** newArray = new Component * [m_componentCount - 1];
    int j = 0;
    //copy the values from the old array to the new array
    for (int i = 0; i < m_componentCount; i++)
    {
        if (name != m_component[i])
        {
            newArray[j] = m_component[i];
            j++;
        }
        else
        {
            componentRemoved = true;
        }
    }

    if (componentRemoved)
    {
        //set the old array to the new array
        delete[] m_component;
        m_component = newArray;
        m_componentCount--;
        delete name;
    }
    else 
    delete[] newArray;

    //returns whether or not the removal was successful.
    return componentRemoved;
}
void Actor::start()
{
    m_started = true;
    
}

void Actor::onCollision(Actor* other)
{
    for (int i = 0; i < m_componentCount; i++)
        m_component[i]->onCollision(other);
}

void Actor::update(float deltaTime)
{
    for (int i = 0; i < m_componentCount; i++)
    {
        if (m_component[i]->getStarted())
            m_component[i]->start();

        m_component[i]->update(deltaTime);
    }
}

void Actor::draw()
{
    for (int i = 0; i < m_componentCount; i++)
        m_component[i]->draw();
}

void Actor::end()
{
    m_started = false;
    for (int i = 0; i < m_componentCount; i++)
        m_component[i]->end();
}

void Actor::onDestroy()
{
    for (int i = 0; i < m_componentCount; i++)
        m_component[i]->onDestroy();

    //Removes this actor from its parent if it has one
    if (getTransform()->getParent())
        getTransform()->getParent()->removeChild(getTransform());
}

bool Actor::checkForCollision(Actor* other)
{
    //Call check collision if there is a collider attached to this actor
    if (m_collider)
        return m_collider->checkCollision(other);

    return false;
}