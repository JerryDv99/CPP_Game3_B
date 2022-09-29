#include "Logo.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CursorManager.h"

Logo::Logo()
{
}

Logo::~Logo()
{
	Release();
}

void Logo::Start()
{
	Buffer[0] = (char*)"             _rL3Md$$D0dmkv!`";
	Buffer[1] = (char*)"          >kD#B##B#########BB5(.";
	Buffer[2] = (char*)"       _XQBB##@@@#Q$D$8B@@@@#BBBWr";
	Buffer[3] = (char*)"     's#BB@##EmwvzVcucVVVVIM#@@#BBR~";
	Buffer[4] = (char*)"    :8#B@##PluVx=v:    `-=}3vsQ@##Q#}";
	Buffer[5] = (char*)"   ~#Q#@@OLK)=rx_ix:    .vz)vGxz#@@Q#j";
	Buffer[6] = (char*)"  .BB#@@}Vk.  ,x)*i~~ .|i?;;}]LHxQ@@Q#i";
	Buffer[7] = (char*)"  V#Q@@myK'    ;~!I-*yr_w);c}- vav@@#BQ`";
	Buffer[8] = (char*)"  BB#@@*Z!    .!Vr^r}z*;'!v - `PVZ@@Q@r ";
	Buffer[9] = (char*)" '#Q@@Qx}!r}T}x<*hYrxlvPTv:`    Vay@@Q#}";
	Buffer[10] = (char*)" `#B#@#vWv<^****_ra|)Yv~=i^**^:`Iza@@Q#v";
	Buffer[11] = (char*)"  6#B@@YVLvvr!,-_|r!;wc*!;^^=(irUvB@@Q#_";
	Buffer[12] = (char*)"  =#Q@@#v3|`     )-cx!v ',:(Vr*dLZ@@8#K";
	Buffer[13] = (char*)"   }@Q@@#Vyc_   .ki-vu      .kzi8##B#$`";
	Buffer[14] = (char*)"    y#Q#@#b}h}!`)u|:Yr   `-(XuI##@B#g- ";
	Buffer[15] = (char*)"     *Q#B#@@DUVwm^ys:L|LVyVkM#@@BB#w`";
	Buffer[16] = (char*)"      `iQ#B#@@@#$OG5a3PMEQ@@@#BBBm'";
	Buffer[17] = (char*)"        '*GBB####@@@@@@@####B#0L.";
	Buffer[18] = (char*)"          `'^uOQB#B#BQQBBQEU)_``";
	Buffer[19] = (char*)"              != < *rxxvxv ?";

	Buffer[20] = (char*)"             `:)}VVLyVVTr^_";
	Buffer[21] = (char*)"         `~VGQQ########B##BDVx_";
	Buffer[22] = (char*)"       'k$8B@@QM3oc}Y}yeP6B@##Bdx`";
	Buffer[23] = (char*)"     .TBB@#dyr*}mylTTTuojv*xU8@#Q$)";
	Buffer[24] = (char*)"    xBB@By*vwz|x`       >x}mc*vW@@Bd,";
	Buffer[25] = (char*)"   uB#@3rv3V:!$#c`     rB#T.^3wrxQ@BB>";
	Buffer[26] = (char*)"  V##@Pr}Z,   w@@E:  .h@@E-   vZr*B@BB:";
	Buffer[27] = (char*)" !##@d*YM`    `k@@QHk$#@8-     !Dr)#@QR`";
	Buffer[28] = (char*)" aB@@r)$_      *dgX6BgH0V-`     uk*3@#@^";
	Buffer[29] = (char*)" 8@@QrrO-ueGZEBdIOZ#@QIG5Q#Qg0dv*O*x@@#i";
	Buffer[30] = (char*)" 6@@$rr9_VPZO$QZr^vQ#Rv*^gO3hyc<rZ*x#@@}";
	Buffer[31] = (char*)" K@@B)rE:      ~*-'^<`._r`      yw*K#@#~";
	Buffer[32] = (char*)" !#@#5*]d`     :  .^~=` ':     ^6r\Q@@O ";
	Buffer[33] = (char*)"  V@@Bjr}Z,   ,` ''  `_` '_   vZr*E#@#: ";
	Buffer[34] = (char*)"   u#@#K))ej=:wk!'     '~VL!\Pu*LE@@8:";
	Buffer[35] = (char*)"    >B@#gV|)VjL]_       :}uki^isQ@@6- ";
	Buffer[36] = (char*)"     .z#@#QIlrrLmylTTTuoUv*xuZB@@#<";
	Buffer[37] = (char*)"       .T8@@#B03ccT}TTlcwZ8B@@BZ*";
	Buffer[38] = (char*)"          'vaB@@@@##B##@@@#ghr'";
	Buffer[39] = (char*)"              -=^YcwyLlx*:`";

	Time = GetTickCount64();
} 
  
     
       
         
             

void Logo::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_RETURN || Time + 6000 < GetTickCount64())
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);
}

void Logo::Render()
{
	if (GetTickCount64() % 300 < 150)
		for (int i = 0; i < 20; ++i)
			CursorManager::GetInstance()->WriteBuffer(55, 8 + i, Buffer[i], 8);
		
		
	if (GetTickCount64() % 300 >= 150)
		for (int i = 20; i < 40; ++i)
			CursorManager::GetInstance()->WriteBuffer(55, -12 + i, Buffer[i], 8);

	if (Time + 4000 > GetTickCount64())
	{
		CursorManager::GetInstance()->WriteBuffer(67, 42, "Now Loading .");
		if (GetTickCount64() % 600 > 200)
			CursorManager::GetInstance()->WriteBuffer(67, 42, "Now Loading . .");
		if (GetTickCount64() % 600 > 400)
			CursorManager::GetInstance()->WriteBuffer(67, 42, "Now Loading . . .");
	}
	else
		CursorManager::GetInstance()->WriteBuffer(70, 42, "Let's Go ! !");
	
	CursorManager::GetInstance()->WriteBuffer(52, 36, "¡Ü¡Ü¡Ü                ¡Ü¡Ü¡Ü                ¡Ü¡Ü¡Ü", 12);

	CursorManager::GetInstance()->WriteBuffer(74, 33, "¡Ü¡Ü¡Ü", 8);
	if (Time + 2000 > GetTickCount64())
		CursorManager::GetInstance()->WriteBuffer(74, 33, "¡Ü", 12);
	else if (Time + 4000 > GetTickCount64())
		CursorManager::GetInstance()->WriteBuffer(76, 33, "¡Ü", 14);
	else if (Time + 4000 < GetTickCount64())
	{
		CursorManager::GetInstance()->WriteBuffer(52, 36, "¡Ü¡Ü¡Ü                ¡Ü¡Ü¡Ü                ¡Ü¡Ü¡Ü", 10);
		CursorManager::GetInstance()->WriteBuffer(78, 33, "¡Ü", 10);
	}
}

void Logo::Release()
{
}