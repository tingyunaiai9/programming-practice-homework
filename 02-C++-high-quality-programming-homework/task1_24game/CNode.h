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
    virtual double calc() { return DBL_MAX; };
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

    virtual double calc();
};

class CLeftBracket :
    public CNode
{
public:
    virtual string get_name() { return "("; };
    virtual bool is_leftbracket() { return true; };
};

class CRightBracket :
    public CNode
{
public:
    virtual string get_name() { return ")"; };
    virtual bool is_rightbracket() { return true; };
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
	virtual int weight() { return 1; };

	virtual double calc();
};

class CMinus :
	public COperator
{
public:
	virtual string get_name() { return "-"; };
	virtual int weight() { return 1; };

	virtual double calc();
};

class CMultiply :
	public COperator
{
public:
	virtual string get_name() { return "*"; };
	virtual int weight() { return 2; };

	virtual double calc();
};

class CDivide :
	public COperator
{
public:
	virtual string get_name() { return "/"; };
	virtual int weight() { return 2; };

	virtual double calc();
};
