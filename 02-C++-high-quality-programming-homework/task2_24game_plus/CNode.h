#pragma once

class CNode
{
protected:
    CNode* m_left;
    CNode* m_right;

public:
    CNode();
    virtual ~CNode();

    virtual string get_name() = 0;

    virtual bool is_degital() { return false; };
    virtual bool is_leftbracket() { return false; };
    virtual bool is_rightbracket() { return false; };
    virtual bool is_operator() { return false; };

    virtual int weight() { return -1; };

    void set_leftnode(CNode* node) { m_left = node; };
    void set_rightnode(CNode* node) { m_right = node; };
    virtual long long calc() { return LLONG_MAX; };
};

class CDegital :
    public CNode
{
private:
    string m_name;

public:
    CDegital(string name);
    virtual ~CDegital();

    virtual string get_name() { return m_name; };
    virtual bool is_degital() { return true; };

    virtual long long calc();
};

class COperator :
    public CNode
{
public:
    virtual bool is_operator() { return true; };
};

class CPlus :
    public COperator
{
public:
    virtual string get_name() { return "+"; };
    virtual int weight() { return 0; };

    virtual long long calc();
};

class CMultiply :
    public COperator
{
public:
    virtual string get_name() { return "*"; };
	virtual int weight() { return 0; };

    virtual long long calc();
};
