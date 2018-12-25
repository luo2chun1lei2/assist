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
	virtual int addElement(const char *elem_name) = 0;
	virtual int addEdge(const char *from_elem_name, const char *to_elem_name) = 0;
};

class IView {
public:
	virtual void show() = 0;
};

class IStorage {
public:
	virtual void save(IRelationMap *p_map) = 0;
};

/**
 * Control all classes inherit these interfaces,
 * not a relation map.
 */
class IEngine {
public:
	IEngine() : p_control(nullptr), p_view(nullptr), p_storage(nullptr) {
	}

	virtual void addControl(IControl * p_control) {
		// TOOD : "add" should "insert instance into a list".
		this->p_control = p_control;
	} virtual void addView(IView * p_view) {
		this->p_view = p_view;
	}
	virtual void addStorage(IStorage * p_storage) {
		this->p_storage = p_storage;
	}

	// show data into view.
	virtual void show() = 0;

protected:
	IControl * p_control;
	IView *p_view;
	IStorage *p_storage;
};
