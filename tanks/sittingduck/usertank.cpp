#include "mytank.hpp"

class UserTank : public MyTank
{
public:
	virtual void Think() {
		RotateBaseBy(DegToRad(15));
	}
};

__declspec(dllexport) MyTank *__cdecl
GetNewUserTank() { return new UserTank; }
