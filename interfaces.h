/**
 * Define the common interfaces for all sub classes.
 */

/**
 * The kernel of data structure.
 */
class IRelationMap
{
public:
};

/**
 * Control a relation map.
 */
class IControl
{
public:
};

class IDisplay
{
public:
};

class IStorage
{
public:
    virtual save(IRelationMap &map);
};

/**
 * Control all classes inherit these interfaces,
 * not a relation map.
 */
class IEngine
{
public:
    IEngine(IRelationMap &map);
    virtual void SwitchRelationMap();
}
