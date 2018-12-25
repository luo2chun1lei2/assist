/**
 * Use graphviz to show the relation.
 */

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
