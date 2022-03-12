#include "ScriptPCH.h"

class StartDualSpec : public PlayerScript
{
public:
	StartDualSpec() : PlayerScript("StartDualSpec") { }

	uint64 guid;
	
    void OnCreate(Player* player)
    {
        guid = player->GetGUID();
    }
	
    void OnLogin(Player* p, bool /*firstLogin*/)
	{
		if (p->GetGUID() != guid)
			return;
			
		p->CastSpell(p, 63680, p->GetGUID());
		p->CastSpell(p, 63624, p->GetGUID());
		p->UpdateSpecCount(2);
	}
};

void AddSC_StartDualSpec() 
{
	new StartDualSpec();
}
