#pragma once
class Transform2D;
class Collider;
class Component;

class Actor
{
public:
    Actor();
    ~Actor();

    /// <param name="x">Position on the x axis</param>
    /// <param name="y">Position on the y axis</param>
    /// <param name="name">The name of this actor.</param>
    Actor(float x, float y, const char* name);

    /// <summary>
    /// </summary>
    /// <returns>If the actors start function has been called.</returns>
    bool getStarted() { return m_started; }

    /// <returns> The transform attached to this actor.</returns>
    Transform2D* getTransform() { return m_transform; }

    /// <summary>
    /// Gets the collider attached to this actor
    /// </summary>
    Collider* getCollider() { return m_collider; }

    /// <summary>
    /// Sets this actors collider
    /// </summary>
    /// <param name="collider">The new collider to attach to the actor</param>
    void setCollider(Collider* collider) { m_collider = collider; }

    /// <summary>
    /// Gets the name of this actor
    /// </summary>
    /// <returns></returns>
    const char* getName() { return m_name; }

    /// <summary>
    /// sets the name of this actor
    /// </summary>
    /// <param name="name"></param>
    void setName(const char* name) { m_name = name; }

    /// <summary>
    /// Gets the first component instance attached to this actor that matches the name.
    /// </summary>
    /// <param name="componentName">The name of the component</param>
    /// <returns>the name of the component instance</returns>
    Component* getComponent(const char* componentName);

    /// <summary>
    /// Adds a component to the end of the component array
    /// </summary>
    /// <param name="component">The new component to attach to the actor</param>
    /// <returns>a reference to the component added to the array</returns>
    Component* addComponent(Component* component);

    /// <summary>
    /// Removes the first instance found that matches the component reference
    /// </summary>
    /// <param name="component">The component to remove from the array</param>
    /// <returns>whether or not the removal was successful</returns>
    bool removeComponent(Component* component);

    /// <summary>
    /// Removes the first instance found that matches the component reference
    /// </summary>
    /// <param name="component">The component to remove from the array</param>
    /// <returns>whether or not the removal was successful</returns>
    bool removeComponent(const char* name);

    /// <summary>
    /// Called during the first update after an actor is added to a scene.
    /// </summary>
    virtual void start();

    /// <summary>
    /// Called every frame
    /// </summary>
    /// <param name="deltaTime">The time that has passed from the previous frame to the current</param>
    virtual void update(float deltaTime);

    /// <summary>
    /// Called every loop to update on screen visuals
    /// </summary>
    virtual void draw();

    /// <summary>
    /// Called when this actor is removed from the scene
    /// </summary>
    virtual void end();

    /// <summary>
    /// Called when this actor is destroyed 
    /// </summary>
    virtual void onDestroy();

    /// <summary>
    /// Checks if a collision occured between this actor and another
    /// </summary>
    /// <param name="other">The actor to check collision against</param>
    virtual bool checkForCollision(Actor* other);

    /// <summary>
    /// Called when a collision between this actor and another occurs. 
    /// </summary>
    /// <param name="other">The actor this actor collided with.</param>
    virtual void onCollision(Actor* other);

protected:
    const char* m_name;

private:
    
    bool m_started;
    Transform2D* m_transform;
    Collider* m_collider;
    Component** m_component;
    unsigned int m_componentCount;
};

