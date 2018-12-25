#pragma once

/**
 * Define the common interfaces for all sub classes.
 */

/**
 * The kernel of data structure.
 */
class IRelationMap {
public:
};

/**
 * Control a relation map.
 */
class IControl {
public:
};

class IView {
public:
};

class IStorage {
public:
	//virtual void save(IRelationMap & map);
};

/**
 * Control all classes inherit these interfaces,
 * not a relation map.
 */
class IEngine {
public:
	//IEngine(IRelationMap & map);
	
	virtual void addControl(IControl *p_control) {
		// TOOD : "add" should "insert instance into a list".
		this->p_control = p_control;
	}
	virtual void addView(IView *p_view) {
		this->p_view = p_view;
	}
	virtual void addStorage(IStorage *p_storage) {
		this->p_storage = p_storage;
	}

protected:
	IControl *p_control;
	IView *p_view;
	IStorage *p_storage;
};
