#pragma once

#include "CMember.h"

class MemberList
{
private:
	list<Member> m_members;
	Member m_defaultMember = Member("default", -1);

public:
	MemberList(Member* members, int size);
	~MemberList();

	Member& operator[](string name);
};

