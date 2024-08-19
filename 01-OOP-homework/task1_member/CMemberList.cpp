#include "CMemberList.h"

MemberList::MemberList(Member* members, int size)
{
	for (int i = 0; i < size; i++)
	{
		m_members.push_back(members[i]);
	}
}

MemberList::~MemberList()
{
}

Member& MemberList::operator[](string name)
{
	for (auto& member : m_members)
	{
		if (member.getName() == name)
		{
			return member;
		}
	}

	// not found
	std::cout << name << " not found";
	return m_defaultMember;
}
