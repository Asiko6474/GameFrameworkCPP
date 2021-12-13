#pragma once
class Actor;
class Component
{
public:
	Component();

	Component(const char* name);
	virtual ~Component();

	/// <summary>
	/// Gets the name of this component.
	/// </summary>
	/// <returns></returns>
	const char* getName() { return m_name; }

	/// <summary>
	/// Gets the actor that this component is attached to.
	/// </summary>
	/// <returns></returns>
	Actor* getOwner() { return m_owner; }

	/// <summary>
	/// Assigns the owner of this component if it doesn't already have one
	/// </summary>
	/// <param name="owner">The new owner of this component</param>
	void assignOwner(Actor* owner);

	/// <summary>
	/// Returns whether or not the start function for this component instance has been called
	/// </summary>
	/// <returns></returns>
	bool getStarted() { return m_started; }

	//Functions called by the actor class.
	virtual void start() {m_started = true;}
	virtual void update(float deltaTime);
	virtual void end();
	virtual void draw();
	virtual void onCollision(Actor* other);
	virtual void onDestroy() {};

private:
	Actor* m_owner;
	const char* m_name;
	bool m_started;
};

