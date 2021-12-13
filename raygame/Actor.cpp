#include "Actor.h"
#include "Transform2D.h"
#include <string.h>
#include "Collider.h"
#include <iostream>

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
        if (strcmp(m_components[i]->getName(), componentName) == 0)
        {
            return m_components[i];
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
        appendArray[i] = m_components[i];
    }
    //set the last value in the new array to be the actor we want to add
    appendArray[m_componentCount] = component;
    //set the old array to hold the values of the new array
    m_components = appendArray;
    m_componentCount++;

    return component;
}

 bool Actor::removeComponent(const char* name)
{
    if (!name)
        return false;

    bool componentRemoved = false;
    Component* componentToDelete;
    //create a new array with a size one greater than our old array
    Component** newArray = new Component * [m_componentCount - 1];
    int j = 0;
    //copy the values from the old array to the new array
    for (int i = 0; i < m_componentCount; i++)
    {
        if (strcmp(m_components[i]->getName(), name) = 0)
        {
            newArray[j] = m_components[i];
            j++;
        }
        else
        {
            componentRemoved = true;
            componentToDelete = m_components[i];
        }
    }

    if (componentRemoved)
    {
        //set the old array to the new array
        delete componentToDelete;
        m_components = newArray;
        m_componentCount--;
    }
        
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
        if (m_components[i]->getStarted())
            m_components[i].start();

        m_components[i]->update(deltaTime);
    }
}

void Actor::draw()
{
    for (int i = 0; i < m_compnentCount; i++)
        m_components[i]->draw();
}

void Actor::end()
{
    m_started = false;
    for (int i = 0; i < m_compnentCount; i++)
        m_components[i]->end();
}

void Actor::onDestroy()
{
    for (int i = 0; i < m_componentCount; i++)
        m_components[i]->onDestroy();

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