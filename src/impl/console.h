/**
 * This is a console to control(edit) relation map.
 */

#pragma once

class Dot {
public:
	Dot() {
	} virtual ~ Dot() {
	}

	virtual void create(const char *name);
	virtual void show();
	virtual void close();
protected:
private:
};
