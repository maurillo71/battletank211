#include "mytank.hpp"

/// Your tank AI code goes here.
class UserTank : public MyTank
{
public:
	/// Handle the think request in this function.
	virtual void Think() {
		RotateBaseBy(DegToRad(15));
	}
};

extern "C" {
	/// \return A new instance of this tank.
	__declspec(dllexport) MyTank *__cdecl
	GetNewUserTank() { return new UserTank; }
}
