#include "primes.h"
#include <assert.h>
#include <stdio.h>

int main()
{
	//test #1
	assert(isPrime(2809451) == 1);
	assert(getPrimesCount(3351862, 5908385) == 166620);
	assert(findNextPrime(2809451) == 2809451);

	//test #2
	assert(isPrime(9313411) == 0);
	assert(getPrimesCount(60564, 3231190) == 226213);
	assert(findNextPrime(9313411) == 9313427);

	//test #3
	assert(isPrime(8395342) == 0);
	assert(getPrimesCount(1805547, 8568752) == 440007);
	assert(findNextPrime(8395342) == 8395349);

	//test #4
	assert(isPrime(7038790) == 0);
	assert(getPrimesCount(4475204, 6698705) == 143100);
	assert(findNextPrime(7038790) == 7038803);

	//test #5
	assert(isPrime(810554) == 0);
	assert(getPrimesCount(341008, 1080870) == 55076);
	assert(findNextPrime(810554) == 810571);

	//test #6
	assert(isPrime(2008365) == 0);
	assert(getPrimesCount(4905601, 9006828) == 260521);
	assert(findNextPrime(2008365) == 2008367);

	//test #7
	assert(isPrime(5228388) == 0);
	assert(getPrimesCount(5011715, 7600467) == 165343);
	assert(findNextPrime(5228388) == 5228389);

	//test #8
	assert(isPrime(2339389) == 0);
	assert(getPrimesCount(1099870, 1382955) == 20182);
	assert(findNextPrime(2339389) == 2339417);

	//test #9
	assert(isPrime(7961247) == 0);
	assert(getPrimesCount(1789648, 2899642) == 75741);
	assert(findNextPrime(7961247) == 7961267);

	//test #10
	assert(isPrime(9980171) == 0);
	assert(getPrimesCount(142439, 4023807) == 271503);
	assert(findNextPrime(9980171) == 9980177);

	//test #11
	assert(isPrime(8618496) == 0);
	assert(getPrimesCount(568916, 7583953) == 466799);
	assert(findNextPrime(8618496) == 8618501);

	//test #12
	assert(isPrime(2175331) == 1);
	assert(getPrimesCount(1068753, 7729335) == 439293);
	assert(findNextPrime(2175331) == 2175331);

	//test #13
	assert(isPrime(3123880) == 0);
	assert(getPrimesCount(1057499, 6677166) == 373394);
	assert(findNextPrime(3123880) == 3123881);

	//test #14
	assert(isPrime(4848479) == 0);
	assert(getPrimesCount(4181541, 9596325) == 344528);
	assert(findNextPrime(4848479) == 4848499);

	//test #15
	assert(isPrime(8141172) == 0);
	assert(getPrimesCount(1652229, 2580873) == 63792);
	assert(findNextPrime(8141172) == 8141183);

	//test #16
	assert(isPrime(3942313) == 0);
	assert(getPrimesCount(6203395, 9079974) == 181528);
	assert(findNextPrime(3942313) == 3942331);

	//test #17
	assert(isPrime(181667) == 1);
	assert(getPrimesCount(741869, 6597139) == 391308);
	assert(findNextPrime(181667) == 181667);

	//test #18
	assert(isPrime(2929438) == 0);
	assert(getPrimesCount(3575254, 9167532) == 357789);
	assert(findNextPrime(2929438) == 2929453);

	//test #19
	assert(isPrime(6237451) == 0);
	assert(getPrimesCount(882517, 8965925) == 530329);
	assert(findNextPrime(6237451) == 6237467);

	//test #20
	assert(isPrime(6562980) == 0);
	assert(getPrimesCount(577908, 3547908) == 205854);
	assert(findNextPrime(6562980) == 6562987);

	//test #21
	assert(isPrime(8464824) == 0);
	assert(getPrimesCount(2335726, 8101783) == 374204);
	assert(findNextPrime(8464824) == 8464837);

	//test #22
	assert(isPrime(3432298) == 0);
	assert(getPrimesCount(379534, 2040807) == 119510);
	assert(findNextPrime(3432298) == 3432329);

	//test #23
	assert(isPrime(2727461) == 0);
	assert(getPrimesCount(6103637, 7019718) == 58401);
	assert(findNextPrime(2727461) == 2727521);

	//test #24
	assert(isPrime(8992868) == 0);
	assert(getPrimesCount(1482800, 7877599) == 419125);
	assert(findNextPrime(8992868) == 8992877);

	//test #25
	assert(isPrime(1590281) == 0);
	assert(getPrimesCount(473203, 8299739) == 519109);
	assert(findNextPrime(1590281) == 1590293);

	//test #26
	assert(isPrime(1813717) == 0);
	assert(getPrimesCount(8458519, 9954536) == 93301);
	assert(findNextPrime(1813717) == 1813729);

	//test #27
	assert(isPrime(6636828) == 0);
	assert(getPrimesCount(4700382, 8786336) == 260170);
	assert(findNextPrime(6636828) == 6636863);

	//test #28
	assert(isPrime(3729325) == 0);
	assert(getPrimesCount(2230943, 4283211) == 136972);
	assert(findNextPrime(3729325) == 3729329);

	//test #29
	assert(isPrime(9035178) == 0);
	assert(getPrimesCount(2123784, 7625516) == 358745);
	assert(findNextPrime(9035178) == 9035183);

	//test #30
	assert(isPrime(153432) == 0);
	assert(getPrimesCount(2743198, 5048428) == 152068);
	assert(findNextPrime(153432) == 153437);

	//test #31
	assert(isPrime(7774569) == 0);
	assert(getPrimesCount(7504658, 9478528) == 123697);
	assert(findNextPrime(7774569) == 7774577);

	//test #32
	assert(isPrime(8523913) == 0);
	assert(getPrimesCount(285116, 829188) == 41255);
	assert(findNextPrime(8523913) == 8523917);

	//test #33
	assert(isPrime(9115665) == 0);
	assert(getPrimesCount(2823603, 6701628) == 252600);
	assert(findNextPrime(9115665) == 9115669);

	//test #34
	assert(isPrime(1262431) == 0);
	assert(getPrimesCount(2891057, 5375164) == 163221);
	assert(findNextPrime(1262431) == 1262441);

	//test #35
	assert(isPrime(6083082) == 0);
	assert(getPrimesCount(1237040, 1499214) == 18581);
	assert(findNextPrime(6083082) == 6083083);

	//test #36
	assert(isPrime(6901010) == 0);
	assert(getPrimesCount(1058035, 4020430) == 201801);
	assert(findNextPrime(6901010) == 6901033);

	//test #37
	assert(isPrime(4392616) == 0);
	assert(getPrimesCount(3949257, 7575194) == 233113);
	assert(findNextPrime(4392616) == 4392653);

	//test #38
	assert(isPrime(258862) == 0);
	assert(getPrimesCount(7048564, 8212537) == 73346);
	assert(findNextPrime(258862) == 258871);

	//test #39
	assert(isPrime(1710751) == 0);
	assert(getPrimesCount(1046544, 3749581) == 184809);
	assert(findNextPrime(1710751) == 1710757);

	//test #40
	assert(isPrime(4879732) == 0);
	assert(getPrimesCount(7776957, 8480225) == 44150);
	assert(findNextPrime(4879732) == 4879733);

	//test #41
	assert(isPrime(7667534) == 0);
	assert(getPrimesCount(3205687, 9795297) == 421369);
	assert(findNextPrime(7667534) == 7667537);

	//test #42
	assert(isPrime(4990798) == 0);
	assert(getPrimesCount(143834, 7139685) == 472165);
	assert(findNextPrime(4990798) == 4990823);

	//test #43
	assert(isPrime(9575367) == 0);
	assert(getPrimesCount(7677252, 9427867) == 109654);
	assert(findNextPrime(9575367) == 9575381);

	//test #44
	assert(isPrime(2748759) == 0);
	assert(getPrimesCount(2322947, 8880441) == 423946);
	assert(findNextPrime(2748759) == 2748769);

	//test #45
	assert(isPrime(4794757) == 0);
	assert(getPrimesCount(2677852, 5061339) == 157335);
	assert(findNextPrime(4794757) == 4794761);

	//test #46
	assert(isPrime(1720677) == 0);
	assert(getPrimesCount(5922213, 8574906) == 167978);
	assert(findNextPrime(1720677) == 1720679);

	//test #47
	assert(isPrime(3819621) == 0);
	assert(getPrimesCount(1257953, 3007829) == 120317);
	assert(findNextPrime(3819621) == 3819631);

	//test #48
	assert(isPrime(5755097) == 0);
	assert(getPrimesCount(1743219, 9183810) == 482777);
	assert(findNextPrime(5755097) == 5755133);

	//test #49
	assert(isPrime(145175) == 0);
	assert(getPrimesCount(2070859, 4381895) == 154335);
	assert(findNextPrime(145175) == 145177);

	//test #50
	assert(isPrime(4022904) == 0);
	assert(getPrimesCount(2963211, 7757155) == 310146);
	assert(findNextPrime(4022904) == 4022911);

	//test #51
	assert(isPrime(7332156) == 0);
	assert(getPrimesCount(863353, 1477920) == 44001);
	assert(findNextPrime(7332156) == 7332161);

	//test #52
	assert(isPrime(7542557) == 0);
	assert(getPrimesCount(7408378, 9226002) == 114059);
	assert(findNextPrime(7542557) == 7542569);

	//test #53
	assert(isPrime(1221323) == 0);
	assert(getPrimesCount(5167492, 7113673) == 124577);
	assert(findNextPrime(1221323) == 1221373);

	//test #54
	assert(isPrime(5142737) == 0);
	assert(getPrimesCount(4824265, 9625534) == 304397);
	assert(findNextPrime(5142737) == 5142751);

	//test #55
	assert(isPrime(5052751) == 0);
	assert(getPrimesCount(2253999, 7713675) == 355411);
	assert(findNextPrime(5052751) == 5052763);

	//test #56
	assert(isPrime(4153975) == 0);
	assert(getPrimesCount(471367, 4589697) == 282431);
	assert(findNextPrime(4153975) == 4153979);

	//test #57
	assert(isPrime(6515849) == 0);
	assert(getPrimesCount(3738195, 3948157) == 13838);
	assert(findNextPrime(6515849) == 6515863);

	//test #58
	assert(isPrime(6487696) == 0);
	assert(getPrimesCount(4339295, 9838934) == 349290);
	assert(findNextPrime(6487696) == 6487751);

	//test #59
	assert(isPrime(3977732) == 0);
	assert(getPrimesCount(83098, 520733) == 35000);
	assert(findNextPrime(3977732) == 3977741);

	//test #60
	assert(isPrime(1185016) == 0);
	assert(getPrimesCount(6047702, 7397547) == 85912);
	assert(findNextPrime(1185016) == 1185017);

	//test #61
	assert(isPrime(4288825) == 0);
	assert(getPrimesCount(4571148, 4645047) == 4799);
	assert(findNextPrime(4288825) == 4288847);

	//test #62
	assert(isPrime(948423) == 0);
	assert(getPrimesCount(6613123, 9376747) == 173956);
	assert(findNextPrime(948423) == 948427);

	//test #63
	assert(isPrime(4070724) == 0);
	assert(getPrimesCount(530275, 7528862) == 466197);
	assert(findNextPrime(4070724) == 4070741);

	//test #64
	assert(isPrime(4089225) == 0);
	assert(getPrimesCount(1773303, 6567421) == 315877);
	assert(findNextPrime(4089225) == 4089227);

	//test #65
	assert(isPrime(9084698) == 0);
	assert(getPrimesCount(1119382, 8174398) == 463565);
	assert(findNextPrime(9084698) == 9084707);

	//test #66
	assert(isPrime(4877168) == 0);
	assert(getPrimesCount(2788016, 8009166) == 337805);
	assert(findNextPrime(4877168) == 4877179);

	//test #67
	assert(isPrime(3461711) == 0);
	assert(getPrimesCount(636237, 8658589) == 529315);
	assert(findNextPrime(3461711) == 3461713);

	//test #68
	assert(isPrime(9370306) == 0);
	assert(getPrimesCount(518636, 1798562) == 92009);
	assert(findNextPrime(9370306) == 9370307);

	//test #69
	assert(isPrime(8669997) == 0);
	assert(getPrimesCount(5719635, 7641097) == 122277);
	assert(findNextPrime(8669997) == 8670007);

	//test #70
	assert(isPrime(6069018) == 0);
	assert(getPrimesCount(3818182, 9341081) == 352510);
	assert(findNextPrime(6069018) == 6069023);

	//test #71
	assert(isPrime(6294919) == 0);
	assert(getPrimesCount(3187565, 9273510) == 390166);
	assert(findNextPrime(6294919) == 6294923);

	//test #72
	assert(isPrime(7981050) == 0);
	assert(getPrimesCount(70617, 3507968) == 243672);
	assert(findNextPrime(7981050) == 7981067);

	//test #73
	assert(isPrime(4740101) == 0);
	assert(getPrimesCount(66, 357642) == 30553);
	assert(findNextPrime(4740101) == 4740103);

	//test #74
	assert(isPrime(496760) == 0);
	assert(getPrimesCount(73715, 6925867) == 464642);
	assert(findNextPrime(496760) == 496763);

	//test #75
	assert(isPrime(9879992) == 0);
	assert(getPrimesCount(2537198, 8259245) == 370450);
	assert(findNextPrime(9879992) == 9879997);

	//test #76
	assert(isPrime(5328572) == 0);
	assert(getPrimesCount(460817, 7564297) == 473807);
	assert(findNextPrime(5328572) == 5328581);

	//test #77
	assert(isPrime(391312) == 0);
	assert(getPrimesCount(3335318, 5740562) == 156968);
	assert(findNextPrime(391312) == 391331);

	//test #78
	assert(isPrime(7959944) == 0);
	assert(getPrimesCount(3998422, 8483382) == 287028);
	assert(findNextPrime(7959944) == 7959971);

	//test #79
	assert(isPrime(7320575) == 0);
	assert(getPrimesCount(412566, 4789507) == 299952);
	assert(findNextPrime(7320575) == 7320589);

	//test #80
	assert(isPrime(3531819) == 0);
	assert(getPrimesCount(3448347, 8729025) == 338758);
	assert(findNextPrime(3531819) == 3531833);

	//test #81
	assert(isPrime(3840117) == 0);
	assert(getPrimesCount(3114004, 5870570) == 180073);
	assert(findNextPrime(3840117) == 3840127);

	//test #82
	assert(isPrime(3003507) == 0);
	assert(getPrimesCount(3275867, 5538366) == 147960);
	assert(findNextPrime(3003507) == 3003527);

	//test #83
	assert(isPrime(6063763) == 0);
	assert(getPrimesCount(3516493, 4654987) == 74778);
	assert(findNextPrime(6063763) == 6063769);

	//test #84
	assert(isPrime(8704560) == 0);
	assert(getPrimesCount(4964954, 4992850) == 1848);
	assert(findNextPrime(8704560) == 8704567);

	//test #85
	assert(isPrime(5029970) == 0);
	assert(getPrimesCount(3139519, 7197253) == 263002);
	assert(findNextPrime(5029970) == 5029991);

	//test #86
	assert(isPrime(7993549) == 1);
	assert(getPrimesCount(5291423, 7995010) == 172122);
	assert(findNextPrime(7993549) == 7993549);

	//test #87
	assert(isPrime(2101376) == 0);
	assert(getPrimesCount(4789067, 8926550) == 263162);
	assert(findNextPrime(2101376) == 2101391);

	//test #88
	assert(isPrime(8616936) == 0);
	assert(getPrimesCount(3172364, 4307622) == 74984);
	assert(findNextPrime(8616936) == 8616947);

	//test #89
	assert(isPrime(7666372) == 0);
	assert(getPrimesCount(7371655, 9338070) == 123367);
	assert(findNextPrime(7666372) == 7666381);

	//test #90
	assert(isPrime(689443) == 0);
	assert(getPrimesCount(779485, 5215923) == 300034);
	assert(findNextPrime(689443) == 689459);

	//test #91
	assert(isPrime(2028052) == 0);
	assert(getPrimesCount(2770988, 5865273) == 202762);
	assert(findNextPrime(2028052) == 2028053);

	//test #92
	assert(isPrime(6611106) == 0);
	assert(getPrimesCount(6567549, 7800715) == 78121);
	assert(findNextPrime(6611106) == 6611141);

	//test #93
	assert(isPrime(2751640) == 0);
	assert(getPrimesCount(1441445, 2628643) == 81756);
	assert(findNextPrime(2751640) == 2751647);

	//test #94
	assert(isPrime(2012238) == 0);
	assert(getPrimesCount(5832133, 8636791) == 177695);
	assert(findNextPrime(2012238) == 2012243);

	//test #95
	assert(isPrime(1366207) == 0);
	assert(getPrimesCount(5406241, 6362448) == 61299);
	assert(findNextPrime(1366207) == 1366213);

	//test #96
	assert(isPrime(4499389) == 1);
	assert(getPrimesCount(5901802, 9592957) == 232874);
	assert(findNextPrime(4499389) == 4499389);

	//test #97
	assert(isPrime(7902224) == 0);
	assert(getPrimesCount(1077714, 2862910) == 123538);
	assert(findNextPrime(7902224) == 7902227);

	//test #98
	assert(isPrime(7297140) == 0);
	assert(getPrimesCount(5473759, 9177027) == 234348);
	assert(findNextPrime(7297140) == 7297181);

	//test #99
	assert(isPrime(460364) == 0);
	assert(getPrimesCount(2759986, 4592130) == 121271);
	assert(findNextPrime(460364) == 460373);

	//test #100
	assert(isPrime(3735172) == 0);
	assert(getPrimesCount(2236801, 7692516) == 355237);
	assert(findNextPrime(3735172) == 3735181);

	//test #101
	assert(isPrime(3340538) == 0);
	assert(getPrimesCount(3861869, 7889852) == 258779);
	assert(findNextPrime(3340538) == 3340549);

	//test #102
	assert(isPrime(1119547) == 0);
	assert(getPrimesCount(5373216, 9688609) == 272758);
	assert(findNextPrime(1119547) == 1119557);

	//test #103
	assert(isPrime(7624487) == 0);
	assert(getPrimesCount(2388485, 8465304) == 393423);
	assert(findNextPrime(7624487) == 7624531);

	//test #104
	assert(isPrime(8281570) == 0);
	assert(getPrimesCount(3804317, 8099802) == 275740);
	assert(findNextPrime(8281570) == 8281571);

	//test #105
	assert(isPrime(7684072) == 0);
	assert(getPrimesCount(219066, 4480041) == 295098);
	assert(findNextPrime(7684072) == 7684087);

	//test #106
	assert(isPrime(986083) == 0);
	assert(getPrimesCount(1184513, 1399400) == 15244);
	assert(findNextPrime(986083) == 986101);

	//test #107
	assert(isPrime(3172335) == 0);
	assert(getPrimesCount(4939993, 8569631) == 230933);
	assert(findNextPrime(3172335) == 3172349);

	//test #108
	assert(isPrime(7986595) == 0);
	assert(getPrimesCount(227635, 805969) == 44159);
	assert(findNextPrime(7986595) == 7986599);

	//test #109
	assert(isPrime(353034) == 0);
	assert(getPrimesCount(1830484, 8733319) == 448633);
	assert(findNextPrime(353034) == 353047);

	//test #110
	assert(isPrime(7195902) == 0);
	assert(getPrimesCount(4705877, 9653028) == 313792);
	assert(findNextPrime(7195902) == 7195907);

	//test #111
	assert(isPrime(8264527) == 0);
	assert(getPrimesCount(3340011, 9070424) == 367260);
	assert(findNextPrime(8264527) == 8264537);

	//test #112
	assert(isPrime(1893327) == 0);
	assert(getPrimesCount(2141824, 8285550) == 399037);
	assert(findNextPrime(1893327) == 1893329);

	//test #113
	assert(isPrime(158799) == 0);
	assert(getPrimesCount(781007, 8070937) == 481706);
	assert(findNextPrime(158799) == 158803);

	//test #114
	assert(isPrime(645915) == 0);
	assert(getPrimesCount(2035072, 7974333) == 386785);
	assert(findNextPrime(645915) == 645937);

	//test #115
	assert(isPrime(596751) == 0);
	assert(getPrimesCount(1010439, 4609009) == 243760);
	assert(findNextPrime(596751) == 596767);

	//test #116
	assert(isPrime(741010) == 0);
	assert(getPrimesCount(3188899, 7308259) == 266735);
	assert(findNextPrime(741010) == 741011);

	//test #117
	assert(isPrime(7341429) == 0);
	assert(getPrimesCount(7594092, 8110588) == 32488);
	assert(findNextPrime(7341429) == 7341443);

	//test #118
	assert(isPrime(9617853) == 0);
	assert(getPrimesCount(2041091, 4655599) == 174266);
	assert(findNextPrime(9617853) == 9617893);

	//test #119
	assert(isPrime(8527485) == 0);
	assert(getPrimesCount(2944687, 8126631) == 334624);
	assert(findNextPrime(8527485) == 8527487);

	//test #120
	assert(isPrime(2790065) == 0);
	assert(getPrimesCount(5990810, 7554201) == 99406);
	assert(findNextPrime(2790065) == 2790077);

	//test #121
	assert(isPrime(5810323) == 1);
	assert(getPrimesCount(2232978, 3121719) == 60049);
	assert(findNextPrime(5810323) == 5810323);

	//test #122
	assert(isPrime(4684380) == 0);
	assert(getPrimesCount(2535031, 6247500) == 243195);
	assert(findNextPrime(4684380) == 4684391);

	//test #123
	assert(isPrime(6095618) == 0);
	assert(getPrimesCount(7093366, 8891785) == 113097);
	assert(findNextPrime(6095618) == 6095627);

	//test #124
	assert(isPrime(5337767) == 0);
	assert(getPrimesCount(2615488, 4274711) == 110290);
	assert(findNextPrime(5337767) == 5337791);

	//test #125
	assert(isPrime(3075519) == 0);
	assert(getPrimesCount(758518, 2879854) == 147898);
	assert(findNextPrime(3075519) == 3075547);

	//test #126
	assert(isPrime(5591385) == 0);
	assert(getPrimesCount(4404553, 8567856) == 265758);
	assert(findNextPrime(5591385) == 5591401);

	//test #127
	assert(isPrime(9679444) == 0);
	assert(getPrimesCount(767065, 2391334) == 114197);
	assert(findNextPrime(9679444) == 9679447);

	//test #128
	assert(isPrime(1573197) == 0);
	assert(getPrimesCount(4852090, 8192704) == 213020);
	assert(findNextPrime(1573197) == 1573207);

	//test #129
	assert(isPrime(8393814) == 0);
	assert(getPrimesCount(515515, 9445275) == 587488);
	assert(findNextPrime(8393814) == 8393821);

	//test #130
	assert(isPrime(50977) == 0);
	assert(getPrimesCount(5323891, 8073257) == 174953);
	assert(findNextPrime(50977) == 50989);

	//test #131
	assert(isPrime(1353363) == 0);
	assert(getPrimesCount(416929, 1554103) == 82804);
	assert(findNextPrime(1353363) == 1353371);

	//test #132
	assert(isPrime(1565569) == 1);
	assert(getPrimesCount(3302539, 6075686) == 180635);
	assert(findNextPrime(1565569) == 1565569);

	//test #133
	assert(isPrime(1447751) == 0);
	assert(getPrimesCount(2928818, 4048851) == 74376);
	assert(findNextPrime(1447751) == 1447759);

	//test #134
	assert(isPrime(9282741) == 0);
	assert(getPrimesCount(1885365, 6146069) == 281178);
	assert(findNextPrime(9282741) == 9282743);

	//test #135
	assert(isPrime(1671829) == 0);
	assert(getPrimesCount(1927440, 3547158) == 109287);
	assert(findNextPrime(1671829) == 1671907);

	//test #136
	assert(isPrime(9038458) == 0);
	assert(getPrimesCount(5805583, 7614222) == 115131);
	assert(findNextPrime(9038458) == 9038467);

	//test #137
	assert(isPrime(9256197) == 0);
	assert(getPrimesCount(6998205, 8555962) == 98144);
	assert(findNextPrime(9256197) == 9256207);

	//test #138
	assert(isPrime(6505005) == 0);
	assert(getPrimesCount(3431057, 4476142) == 68758);
	assert(findNextPrime(6505005) == 6505013);

	//test #139
	assert(isPrime(6190480) == 0);
	assert(getPrimesCount(394110, 9180358) == 580279);
	assert(findNextPrime(6190480) == 6190487);

	//test #140
	assert(isPrime(1362197) == 0);
	assert(getPrimesCount(63589, 6352630) == 429056);
	assert(findNextPrime(1362197) == 1362203);

	//test #141
	assert(isPrime(9229054) == 0);
	assert(getPrimesCount(2636272, 4145438) == 100385);
	assert(findNextPrime(9229054) == 9229057);

	//test #142
	assert(isPrime(3636512) == 0);
	assert(getPrimesCount(4775798, 5972793) == 77233);
	assert(findNextPrime(3636512) == 3636527);

	//test #143
	assert(isPrime(4525558) == 0);
	assert(getPrimesCount(2927573, 8933518) == 386370);
	assert(findNextPrime(4525558) == 4525567);

	//test #144
	assert(isPrime(7217319) == 0);
	assert(getPrimesCount(3279685, 4831781) == 101919);
	assert(findNextPrime(7217319) == 7217323);

	//test #145
	assert(isPrime(6279765) == 0);
	assert(getPrimesCount(591954, 9737792) == 599930);
	assert(findNextPrime(6279765) == 6279773);

	//test #146
	assert(isPrime(9062528) == 0);
	assert(getPrimesCount(5467991, 8356127) == 183400);
	assert(findNextPrime(9062528) == 9062539);

	//test #147
	assert(isPrime(8881945) == 0);
	assert(getPrimesCount(3727723, 9093668) == 343037);
	assert(findNextPrime(8881945) == 8881969);

	//test #148
	assert(isPrime(3474632) == 0);
	assert(getPrimesCount(784965, 9365269) == 562420);
	assert(findNextPrime(3474632) == 3474641);

	//test #149
	assert(isPrime(1848836) == 0);
	assert(getPrimesCount(1939476, 8695938) == 438689);
	assert(findNextPrime(1848836) == 1848841);

	//test #150
	assert(isPrime(2971070) == 0);
	assert(getPrimesCount(2732563, 3205145) == 31724);
	assert(findNextPrime(2971070) == 2971081);

	//test #151
	assert(isPrime(881410) == 0);
	assert(getPrimesCount(3815385, 9771738) == 379491);
	assert(findNextPrime(881410) == 881411);

	//test #152
	assert(isPrime(1489603) == 0);
	assert(getPrimesCount(4325913, 6055344) == 111884);
	assert(findNextPrime(1489603) == 1489613);

	//test #153
	assert(isPrime(535) == 0);
	assert(getPrimesCount(3614144, 6911909) == 213336);
	assert(findNextPrime(535) == 541);

	//test #154
	assert(isPrime(3570634) == 0);
	assert(getPrimesCount(3370931, 9113205) == 367886);
	assert(findNextPrime(3570634) == 3570643);

	//test #155
	assert(isPrime(29592) == 0);
	assert(getPrimesCount(2957392, 7682581) == 305858);
	assert(findNextPrime(29592) == 29599);

	//test #156
	assert(isPrime(714032) == 0);
	assert(getPrimesCount(7912223, 8327889) == 26087);
	assert(findNextPrime(714032) == 714037);

	//test #157
	assert(isPrime(6682730) == 0);
	assert(getPrimesCount(2387857, 6123726) == 245307);
	assert(findNextPrime(6682730) == 6682747);

	//test #158
	assert(isPrime(5772184) == 0);
	assert(getPrimesCount(5036320, 5829547) == 51030);
	assert(findNextPrime(5772184) == 5772187);

	//test #159
	assert(isPrime(212515) == 0);
	assert(getPrimesCount(460410, 9120196) == 571428);
	assert(findNextPrime(212515) == 212557);

	//test #160
	assert(isPrime(825480) == 0);
	assert(getPrimesCount(1034059, 3393705) == 162130);
	assert(findNextPrime(825480) == 825491);

	//test #161
	assert(isPrime(6259630) == 0);
	assert(getPrimesCount(3617707, 8308168) == 301165);
	assert(findNextPrime(6259630) == 6259651);

	//test #162
	assert(isPrime(6852559) == 0);
	assert(getPrimesCount(209371, 4108857) == 271597);
	assert(findNextPrime(6852559) == 6852569);

	//test #163
	assert(isPrime(125301) == 0);
	assert(getPrimesCount(559078, 7729224) == 476743);
	assert(findNextPrime(125301) == 125303);

	//test #164
	assert(isPrime(203167) == 0);
	assert(getPrimesCount(2770872, 4632019) == 123134);
	assert(findNextPrime(203167) == 203173);

	//test #165
	assert(isPrime(1985936) == 0);
	assert(getPrimesCount(1519996, 7744917) == 408124);
	assert(findNextPrime(1985936) == 1985939);

	//test #166
	assert(isPrime(7152457) == 0);
	assert(getPrimesCount(1961113, 5259704) == 219033);
	assert(findNextPrime(7152457) == 7152487);

	//test #167
	assert(isPrime(6611771) == 0);
	assert(getPrimesCount(6598890, 8607328) == 126812);
	assert(findNextPrime(6611771) == 6611777);

	//test #168
	assert(isPrime(1473806) == 0);
	assert(getPrimesCount(2293876, 2409604) == 7847);
	assert(findNextPrime(1473806) == 1473841);

	//test #169
	assert(isPrime(3503929) == 0);
	assert(getPrimesCount(8843269, 9368475) == 32777);
	assert(findNextPrime(3503929) == 3503933);

	//test #170
	assert(isPrime(7354240) == 0);
	assert(getPrimesCount(3491966, 7777948) == 276155);
	assert(findNextPrime(7354240) == 7354241);

	//test #171
	assert(isPrime(2722722) == 0);
	assert(getPrimesCount(3487939, 5616985) == 138930);
	assert(findNextPrime(2722722) == 2722729);

	//test #172
	assert(isPrime(5203270) == 0);
	assert(getPrimesCount(7695554, 9502641) == 113124);
	assert(findNextPrime(5203270) == 5203271);

	//test #173
	assert(isPrime(8383661) == 0);
	assert(getPrimesCount(3243572, 9984336) == 430476);
	assert(findNextPrime(8383661) == 8383673);

	//test #174
	assert(isPrime(8539633) == 0);
	assert(getPrimesCount(1048356, 8064427) == 461822);
	assert(findNextPrime(8539633) == 8539669);

	//test #175
	assert(isPrime(8542961) == 0);
	assert(getPrimesCount(248606, 7101036) == 461167);
	assert(findNextPrime(8542961) == 8542973);

	//test #176
	assert(isPrime(1218682) == 0);
	assert(getPrimesCount(7838808, 8976225) == 71363);
	assert(findNextPrime(1218682) == 1218683);

	//test #177
	assert(isPrime(2684660) == 0);
	assert(getPrimesCount(13735, 6169652) == 422101);
	assert(findNextPrime(2684660) == 2684663);

	//test #178
	assert(isPrime(942624) == 0);
	assert(getPrimesCount(5298043, 9727217) == 279963);
	assert(findNextPrime(942624) == 942637);

	//test #179
	assert(isPrime(7553728) == 0);
	assert(getPrimesCount(4337540, 9594081) == 334192);
	assert(findNextPrime(7553728) == 7553731);

	//test #180
	assert(isPrime(1136104) == 0);
	assert(getPrimesCount(5243455, 8827249) == 227472);
	assert(findNextPrime(1136104) == 1136111);

	//test #181
	assert(isPrime(5135924) == 0);
	assert(getPrimesCount(6281280, 6579482) == 18990);
	assert(findNextPrime(5135924) == 5135953);

	//test #182
	assert(isPrime(8104665) == 0);
	assert(getPrimesCount(2434677, 3515549) == 72542);
	assert(findNextPrime(8104665) == 8104667);

	//test #183
	assert(isPrime(8772258) == 0);
	assert(getPrimesCount(3101993, 5580871) == 162356);
	assert(findNextPrime(8772258) == 8772259);

	//test #184
	assert(isPrime(4207516) == 0);
	assert(getPrimesCount(2506875, 7160824) == 303306);
	assert(findNextPrime(4207516) == 4207571);

	//test #185
	assert(isPrime(5809100) == 0);
	assert(getPrimesCount(7349576, 9695452) == 147010);
	assert(findNextPrime(5809100) == 5809103);

	//test #186
	assert(isPrime(2546335) == 0);
	assert(getPrimesCount(3329553, 7226902) == 252150);
	assert(findNextPrime(2546335) == 2546339);

	//test #187
	assert(isPrime(992250) == 0);
	assert(getPrimesCount(1056851, 3073806) == 139105);
	assert(findNextPrime(992250) == 992263);

	//test #188
	assert(isPrime(9519120) == 0);
	assert(getPrimesCount(2647465, 9514524) == 441417);
	assert(findNextPrime(9519120) == 9519121);

	//test #189
	assert(isPrime(6334188) == 0);
	assert(getPrimesCount(4318388, 5340530) == 66484);
	assert(findNextPrime(6334188) == 6334231);

	//test #190
	assert(isPrime(24931) == 0);
	assert(getPrimesCount(1545293, 2317307) == 53355);
	assert(findNextPrime(24931) == 24943);

	//test #191
	assert(isPrime(1468506) == 0);
	assert(getPrimesCount(3566205, 6450037) == 187076);
	assert(findNextPrime(1468506) == 1468507);

	//test #192
	assert(isPrime(5923390) == 0);
	assert(getPrimesCount(1624260, 4129333) == 168840);
	assert(findNextPrime(5923390) == 5923433);

	//test #193
	assert(isPrime(2449842) == 0);
	assert(getPrimesCount(2286207, 9527088) == 466709);
	assert(findNextPrime(2449842) == 2449847);

	//test #194
	assert(isPrime(9283077) == 0);
	assert(getPrimesCount(6127246, 7017754) == 56771);
	assert(findNextPrime(9283077) == 9283093);

	//test #195
	assert(isPrime(9976992) == 0);
	assert(getPrimesCount(7582465, 8501885) == 57805);
	assert(findNextPrime(9976992) == 9977021);

	//test #196
	assert(isPrime(5774562) == 0);
	assert(getPrimesCount(4809381, 7343862) == 162349);
	assert(findNextPrime(5774562) == 5774569);

	//test #197
	assert(isPrime(9411151) == 0);
	assert(getPrimesCount(6239854, 6965456) == 46304);
	assert(findNextPrime(9411151) == 9411161);

	//test #198
	assert(isPrime(5755571) == 0);
	assert(getPrimesCount(1956493, 7585960) == 367699);
	assert(findNextPrime(5755571) == 5755577);

	//test #199
	assert(isPrime(9977410) == 0);
	assert(getPrimesCount(4322338, 8321246) == 255662);
	assert(findNextPrime(9977410) == 9977411);

	//test #200
	assert(isPrime(1878076) == 0);
	assert(getPrimesCount(3252574, 7711303) == 287855);
	assert(findNextPrime(1878076) == 1878089);

	//test #201
	assert(isPrime(1950544) == 0);
	assert(getPrimesCount(430335, 5262080) == 329272);
	assert(findNextPrime(1950544) == 1950577);

	//test #202
	assert(isPrime(4939941) == 0);
	assert(getPrimesCount(3754145, 5789344) == 132302);
	assert(findNextPrime(4939941) == 4939973);

	//test #203
	assert(isPrime(3422485) == 0);
	assert(getPrimesCount(830801, 2212814) == 97339);
	assert(findNextPrime(3422485) == 3422501);

	//test #204
	assert(isPrime(4175897) == 0);
	assert(getPrimesCount(3488431, 6128353) == 171685);
	assert(findNextPrime(4175897) == 4175933);

	//test #205
	assert(isPrime(6526253) == 0);
	assert(getPrimesCount(135799, 7210383) == 477322);
	assert(findNextPrime(6526253) == 6526277);

	//test #206
	assert(isPrime(6500375) == 0);
	assert(getPrimesCount(2801230, 4424289) == 107503);
	assert(findNextPrime(6500375) == 6500387);

	//test #207
	assert(isPrime(3625745) == 0);
	assert(getPrimesCount(2653035, 6584628) == 256723);
	assert(findNextPrime(3625745) == 3625759);

	//test #208
	assert(isPrime(7048117) == 0);
	assert(getPrimesCount(1245172, 9908223) == 562828);
	assert(findNextPrime(7048117) == 7048127);

	//test #209
	assert(isPrime(3492927) == 0);
	assert(getPrimesCount(2873975, 7345360) == 290115);
	assert(findNextPrime(3492927) == 3492953);

	//test #210
	assert(isPrime(7127689) == 1);
	assert(getPrimesCount(1411654, 8334406) == 452830);
	assert(findNextPrime(7127689) == 7127689);

	//test #211
	assert(isPrime(7472366) == 0);
	assert(getPrimesCount(3657121, 8046143) == 282147);
	assert(findNextPrime(7472366) == 7472369);

	//test #212
	assert(isPrime(435233) == 0);
	assert(getPrimesCount(4815842, 5505463) == 44680);
	assert(findNextPrime(435233) == 435247);

	//test #213
	assert(isPrime(508362) == 0);
	assert(getPrimesCount(1227811, 2607133) == 95452);
	assert(findNextPrime(508362) == 508363);

	//test #214
	assert(isPrime(569979) == 0);
	assert(getPrimesCount(144142, 2458286) == 166893);
	assert(findNextPrime(569979) == 569983);

	//test #215
	assert(isPrime(9770925) == 0);
	assert(getPrimesCount(1430002, 8822082) == 482161);
	assert(findNextPrime(9770925) == 9770939);

	//test #216
	assert(isPrime(5661003) == 0);
	assert(getPrimesCount(2056908, 3868549) == 121680);
	assert(findNextPrime(5661003) == 5661041);

	//test #217
	assert(isPrime(4039677) == 0);
	assert(getPrimesCount(3278982, 8317479) == 324170);
	assert(findNextPrime(4039677) == 4039681);

	//test #218
	assert(isPrime(5090041) == 0);
	assert(getPrimesCount(3230690, 9278020) == 387513);
	assert(findNextPrime(5090041) == 5090077);

	//test #219
	assert(isPrime(4488770) == 0);
	assert(getPrimesCount(4621663, 4703309) == 5321);
	assert(findNextPrime(4488770) == 4488773);

	//test #220
	assert(isPrime(3707461) == 1);
	assert(getPrimesCount(208157, 7650043) == 499094);
	assert(findNextPrime(3707461) == 3707461);

	//test #221
	assert(isPrime(8570771) == 0);
	assert(getPrimesCount(2980387, 9182618) == 398332);
	assert(findNextPrime(8570771) == 8570797);

	//test #222
	assert(isPrime(2034078) == 0);
	assert(getPrimesCount(5798790, 9599500) == 239906);
	assert(findNextPrime(2034078) == 2034103);

	//test #223
	assert(isPrime(6946280) == 0);
	assert(getPrimesCount(982906, 8416947) == 488669);
	assert(findNextPrime(6946280) == 6946301);

	//test #224
	assert(isPrime(2002238) == 0);
	assert(getPrimesCount(3429554, 5487274) == 134451);
	assert(findNextPrime(2002238) == 2002249);

	//test #225
	assert(isPrime(6587109) == 0);
	assert(getPrimesCount(7745599, 7907126) == 10189);
	assert(findNextPrime(6587109) == 6587111);

	//test #226
	assert(isPrime(96301) == 0);
	assert(getPrimesCount(8734436, 9013302) == 17369);
	assert(findNextPrime(96301) == 96323);

	//test #227
	assert(isPrime(985301) == 1);
	assert(getPrimesCount(6045151, 9951345) == 245865);
	assert(findNextPrime(985301) == 985301);

	//test #228
	assert(isPrime(6994113) == 0);
	assert(getPrimesCount(2689475, 5822409) == 205514);
	assert(findNextPrime(6994113) == 6994121);

	//test #229
	assert(isPrime(1619861) == 1);
	assert(getPrimesCount(3165582, 4164163) == 66085);
	assert(findNextPrime(1619861) == 1619861);

	//test #230
	assert(isPrime(3529383) == 0);
	assert(getPrimesCount(3507002, 8741711) == 335743);
	assert(findNextPrime(3529383) == 3529417);

	//test #231
	assert(isPrime(1788985) == 0);
	assert(getPrimesCount(3384501, 3436624) == 3508);
	assert(findNextPrime(1788985) == 1788991);

	//test #232
	assert(isPrime(9003054) == 0);
	assert(getPrimesCount(707219, 2472485) == 124118);
	assert(findNextPrime(9003054) == 9003061);

	//test #233
	assert(isPrime(2584801) == 0);
	assert(getPrimesCount(2913122, 3173701) == 17457);
	assert(findNextPrime(2584801) == 2584807);

	//test #234
	assert(isPrime(6186466) == 0);
	assert(getPrimesCount(3148716, 3355666) == 13840);
	assert(findNextPrime(6186466) == 6186493);

	//test #235
	assert(isPrime(2763750) == 0);
	assert(getPrimesCount(2530522, 4831709) == 152318);
	assert(findNextPrime(2763750) == 2763751);

	//test #236
	assert(isPrime(7365397) == 0);
	assert(getPrimesCount(2682834, 9416720) == 432972);
	assert(findNextPrime(7365397) == 7365401);

	//test #237
	assert(isPrime(435806) == 0);
	assert(getPrimesCount(9180194, 9344334) == 10245);
	assert(findNextPrime(435806) == 435817);

	//test #238
	assert(isPrime(7606805) == 0);
	assert(getPrimesCount(242425, 3477813) == 227284);
	assert(findNextPrime(7606805) == 7606817);

	//test #239
	assert(isPrime(8046852) == 0);
	assert(getPrimesCount(1982941, 8841415) == 444825);
	assert(findNextPrime(8046852) == 8046869);

	//test #240
	assert(isPrime(1613901) == 0);
	assert(getPrimesCount(5862189, 6693001) == 53072);
	assert(findNextPrime(1613901) == 1613921);

	//test #241
	assert(isPrime(2945754) == 0);
	assert(getPrimesCount(8009614, 8295750) == 17944);
	assert(findNextPrime(2945754) == 2945773);

	//test #242
	assert(isPrime(2008808) == 0);
	assert(getPrimesCount(4973298, 7095528) == 135968);
	assert(findNextPrime(2008808) == 2008817);

	//test #243
	assert(isPrime(5023740) == 0);
	assert(getPrimesCount(5224263, 7770321) == 162307);
	assert(findNextPrime(5023740) == 5023751);

	//test #244
	assert(isPrime(7550067) == 0);
	assert(getPrimesCount(4575522, 6394477) == 117204);
	assert(findNextPrime(7550067) == 7550071);

	//test #245
	assert(isPrime(1417719) == 0);
	assert(getPrimesCount(609277, 4145081) == 242886);
	assert(findNextPrime(1417719) == 1417727);

	//test #246
	assert(isPrime(6802366) == 0);
	assert(getPrimesCount(3312590, 4594997) == 84385);
	assert(findNextPrime(6802366) == 6802373);

	//test #247
	assert(isPrime(3910834) == 0);
	assert(getPrimesCount(4920301, 6284617) == 87773);
	assert(findNextPrime(3910834) == 3910843);

	//test #248
	assert(isPrime(5726858) == 0);
	assert(getPrimesCount(1730773, 3761204) == 137195);
	assert(findNextPrime(5726858) == 5726867);

	//test #249
	assert(isPrime(4500384) == 0);
	assert(getPrimesCount(3665344, 6432717) == 179416);
	assert(findNextPrime(4500384) == 4500401);

	//test #250
	assert(isPrime(1739205) == 0);
	assert(getPrimesCount(6458232, 6875935) == 26639);
	assert(findNextPrime(1739205) == 1739207);

	//test #251
	assert(isPrime(105417) == 0);
	assert(getPrimesCount(900482, 6229663) == 356223);
	assert(findNextPrime(105417) == 105437);

	//test #252
	assert(isPrime(9798118) == 0);
	assert(getPrimesCount(1078953, 1279843) == 14411);
	assert(findNextPrime(9798118) == 9798149);

	//test #253
	assert(isPrime(2603280) == 0);
	assert(getPrimesCount(1668871, 2612448) == 64741);
	assert(findNextPrime(2603280) == 2603281);

	//test #254
	assert(isPrime(9826699) == 0);
	assert(getPrimesCount(4245886, 7881816) == 233043);
	assert(findNextPrime(9826699) == 9826709);

	//test #255
	assert(isPrime(3011536) == 0);
	assert(getPrimesCount(6531149, 6881997) == 22375);
	assert(findNextPrime(3011536) == 3011543);

	//test #256
	assert(isPrime(6603902) == 0);
	assert(getPrimesCount(1405214, 6216675) == 319224);
	assert(findNextPrime(6603902) == 6603907);

	//test #257
	assert(isPrime(4940279) == 1);
	assert(getPrimesCount(2329789, 3592067) == 84672);
	assert(findNextPrime(4940279) == 4940279);

	//test #258
	assert(isPrime(4011963) == 0);
	assert(getPrimesCount(1841489, 5854762) == 265573);
	assert(findNextPrime(4011963) == 4011977);

	//test #259
	assert(isPrime(685861) == 0);
	assert(getPrimesCount(1854624, 4037468) == 146771);
	assert(findNextPrime(685861) == 685907);

	//test #260
	assert(isPrime(5231998) == 0);
	assert(getPrimesCount(6153892, 7735518) == 100425);
	assert(findNextPrime(5231998) == 5232023);

	//test #261
	assert(isPrime(1459482) == 0);
	assert(getPrimesCount(1372443, 2517195) == 79099);
	assert(findNextPrime(1459482) == 1459517);

	//test #262
	assert(isPrime(7485978) == 0);
	assert(getPrimesCount(168475, 4686857) == 312742);
	assert(findNextPrime(7485978) == 7485997);

	//test #263
	assert(isPrime(5446114) == 0);
	assert(getPrimesCount(839158, 4469191) == 247096);
	assert(findNextPrime(5446114) == 5446127);

	//test #264
	assert(isPrime(6830398) == 0);
	assert(getPrimesCount(6780950, 6789128) == 516);
	assert(findNextPrime(6830398) == 6830407);

	//test #265
	assert(isPrime(8898269) == 0);
	assert(getPrimesCount(2073157, 8670147) == 427870);
	assert(findNextPrime(8898269) == 8898283);

	//test #266
	assert(isPrime(3689536) == 0);
	assert(getPrimesCount(1861132, 5214326) == 223017);
	assert(findNextPrime(3689536) == 3689551);

	//test #267
	assert(isPrime(6115095) == 0);
	assert(getPrimesCount(1491964, 2386186) == 61746);
	assert(findNextPrime(6115095) == 6115097);

	//test #268
	assert(isPrime(7277961) == 0);
	assert(getPrimesCount(2769962, 9330700) == 421723);
	assert(findNextPrime(7277961) == 7277981);

	//test #269
	assert(isPrime(6607274) == 0);
	assert(getPrimesCount(6512389, 8938048) == 153059);
	assert(findNextPrime(6607274) == 6607283);

	//test #270
	assert(isPrime(3048235) == 0);
	assert(getPrimesCount(426792, 7458746) == 469776);
	assert(findNextPrime(3048235) == 3048247);

	//test #271
	assert(isPrime(8660003) == 0);
	assert(getPrimesCount(426327, 1898888) == 106088);
	assert(findNextPrime(8660003) == 8660033);

	//test #272
	assert(isPrime(3915805) == 0);
	assert(getPrimesCount(3512332, 3602158) == 5911);
	assert(findNextPrime(3915805) == 3915809);

	//test #273
	assert(isPrime(2931862) == 0);
	assert(getPrimesCount(3163999, 4678923) == 99796);
	assert(findNextPrime(2931862) == 2931883);

	//test #274
	assert(isPrime(3327480) == 0);
	assert(getPrimesCount(1988019, 2746971) == 51703);
	assert(findNextPrime(3327480) == 3327491);

	//test #275
	assert(isPrime(6596382) == 0);
	assert(getPrimesCount(5722619, 9083414) == 212550);
	assert(findNextPrime(6596382) == 6596383);

	//test #276
	assert(isPrime(2058956) == 0);
	assert(getPrimesCount(1401738, 6430356) == 333104);
	assert(findNextPrime(2058956) == 2058967);

	//test #277
	assert(isPrime(1511912) == 0);
	assert(getPrimesCount(2783686, 8558258) == 372552);
	assert(findNextPrime(1511912) == 1511921);

	//test #278
	assert(isPrime(3060242) == 0);
	assert(getPrimesCount(5195368, 5765548) == 36708);
	assert(findNextPrime(3060242) == 3060247);

	//test #279
	assert(isPrime(1276306) == 0);
	assert(getPrimesCount(7794952, 9305067) == 94666);
	assert(findNextPrime(1276306) == 1276307);

	//test #280
	assert(isPrime(9552667) == 0);
	assert(getPrimesCount(1136066, 6145986) == 333861);
	assert(findNextPrime(9552667) == 9552689);

	//test #281
	assert(isPrime(1864417) == 1);
	assert(getPrimesCount(3383985, 5464750) == 136080);
	assert(findNextPrime(1864417) == 1864417);

	//test #282
	assert(isPrime(7467361) == 0);
	assert(getPrimesCount(3443594, 5864671) == 157654);
	assert(findNextPrime(7467361) == 7467401);

	//test #283
	assert(isPrime(3362439) == 0);
	assert(getPrimesCount(2494940, 8150850) == 366485);
	assert(findNextPrime(3362439) == 3362441);

	//test #284
	assert(isPrime(5587268) == 0);
	assert(getPrimesCount(4462296, 7453598) == 191896);
	assert(findNextPrime(5587268) == 5587277);

	//test #285
	assert(isPrime(4539645) == 0);
	assert(getPrimesCount(3962403, 9070859) == 326135);
	assert(findNextPrime(4539645) == 4539649);

	//test #286
	assert(isPrime(3776307) == 0);
	assert(getPrimesCount(1975906, 3498550) == 102803);
	assert(findNextPrime(3776307) == 3776317);

	//test #287
	assert(isPrime(4421141) == 1);
	assert(getPrimesCount(4619134, 7054558) == 156442);
	assert(findNextPrime(4421141) == 4421141);

	//test #288
	assert(isPrime(3205070) == 0);
	assert(getPrimesCount(6683327, 7981197) == 82168);
	assert(findNextPrime(3205070) == 3205087);

	//test #289
	assert(isPrime(7966984) == 0);
	assert(getPrimesCount(86155, 4297464) == 294279);
	assert(findNextPrime(7966984) == 7967009);

	//test #290
	assert(isPrime(1528221) == 0);
	assert(getPrimesCount(3304175, 3512378) == 13799);
	assert(findNextPrime(1528221) == 1528223);

	//test #291
	assert(isPrime(9310890) == 0);
	assert(getPrimesCount(2626871, 8764665) == 396119);
	assert(findNextPrime(9310890) == 9310901);

	//test #292
	assert(isPrime(9666114) == 0);
	assert(getPrimesCount(535242, 7983271) == 494513);
	assert(findNextPrime(9666114) == 9666131);

	//test #293
	assert(isPrime(1792144) == 0);
	assert(getPrimesCount(7595106, 9635423) == 127784);
	assert(findNextPrime(1792144) == 1792159);

	//test #294
	assert(isPrime(2214638) == 0);
	assert(getPrimesCount(6202537, 6624060) == 26890);
	assert(findNextPrime(2214638) == 2214661);

	//test #295
	assert(isPrime(181009) == 0);
	assert(getPrimesCount(3862642, 8238423) == 280600);
	assert(findNextPrime(181009) == 181019);

	//test #296
	assert(isPrime(8242280) == 0);
	assert(getPrimesCount(1887320, 5276855) == 225264);
	assert(findNextPrime(8242280) == 8242301);

	//test #297
	assert(isPrime(9279813) == 0);
	assert(getPrimesCount(1686171, 3742342) == 139045);
	assert(findNextPrime(9279813) == 9279863);

	//test #298
	assert(isPrime(9892843) == 0);
	assert(getPrimesCount(2861755, 5651977) == 182950);
	assert(findNextPrime(9892843) == 9892859);

	//test #299
	assert(isPrime(7090363) == 0);
	assert(getPrimesCount(1862203, 2451391) == 40371);
	assert(findNextPrime(7090363) == 7090387);

	//test #300
	assert(isPrime(1112581) == 1);
	assert(getPrimesCount(6011637, 8350693) == 148179);
	assert(findNextPrime(1112581) == 1112581);

	//test #301
	assert(isPrime(1447677) == 0);
	assert(getPrimesCount(1021085, 9778098) == 570841);
	assert(findNextPrime(1447677) == 1447711);

	//test #302
	assert(isPrime(8883849) == 0);
	assert(getPrimesCount(5538372, 8889166) == 212284);
	assert(findNextPrime(8883849) == 8883883);

	//test #303
	assert(isPrime(7746176) == 0);
	assert(getPrimesCount(2182145, 7446953) == 343473);
	assert(findNextPrime(7746176) == 7746181);

	//test #304
	assert(isPrime(2132106) == 0);
	assert(getPrimesCount(96778, 6224105) == 417850);
	assert(findNextPrime(2132106) == 2132107);

	//test #305
	assert(isPrime(3896694) == 0);
	assert(getPrimesCount(721210, 7441953) == 446488);
	assert(findNextPrime(3896694) == 3896699);

	//test #306
	assert(isPrime(8578487) == 0);
	assert(getPrimesCount(5608075, 9095047) == 220657);
	assert(findNextPrime(8578487) == 8578513);

	//test #307
	assert(isPrime(5598695) == 0);
	assert(getPrimesCount(2110715, 8648200) == 423895);
	assert(findNextPrime(5598695) == 5598701);

	//test #308
	assert(isPrime(7767542) == 0);
	assert(getPrimesCount(918803, 5787247) == 326529);
	assert(findNextPrime(7767542) == 7767547);

	//test #309
	assert(isPrime(3629142) == 0);
	assert(getPrimesCount(2795725, 6271805) == 227163);
	assert(findNextPrime(3629142) == 3629159);

	//test #310
	assert(isPrime(6142440) == 0);
	assert(getPrimesCount(1048995, 9458240) == 548928);
	assert(findNextPrime(6142440) == 6142441);

	//test #311
	assert(isPrime(5412389) == 0);
	assert(getPrimesCount(7441111, 7717279) == 17434);
	assert(findNextPrime(5412389) == 5412391);

	//test #312
	assert(isPrime(6582691) == 1);
	assert(getPrimesCount(377323, 1212748) == 61728);
	assert(findNextPrime(6582691) == 6582691);

	//test #313
	assert(isPrime(4849600) == 0);
	assert(getPrimesCount(2849939, 8630045) == 372547);
	assert(findNextPrime(4849600) == 4849613);

	//test #314
	assert(isPrime(5477135) == 0);
	assert(getPrimesCount(3329886, 4103467) == 51088);
	assert(findNextPrime(5477135) == 5477137);

	//test #315
	assert(isPrime(429335) == 0);
	assert(getPrimesCount(8497866, 8886464) == 24371);
	assert(findNextPrime(429335) == 429347);

	//test #316
	assert(isPrime(3776724) == 0);
	assert(getPrimesCount(168800, 4506506) == 300989);
	assert(findNextPrime(3776724) == 3776743);

	//test #317
	assert(isPrime(873320) == 0);
	assert(getPrimesCount(1192838, 9773828) == 558198);
	assert(findNextPrime(873320) == 873331);

	//test #318
	assert(isPrime(4654661) == 0);
	assert(getPrimesCount(612798, 6851732) == 417105);
	assert(findNextPrime(4654661) == 4654669);

	//test #319
	assert(isPrime(7661967) == 0);
	assert(getPrimesCount(882637, 7503599) == 438456);
	assert(findNextPrime(7661967) == 7661981);

	//test #320
	assert(isPrime(751399) == 0);
	assert(getPrimesCount(3825920, 7223086) == 219045);
	assert(findNextPrime(751399) == 751411);

	//test #321
	assert(isPrime(9072582) == 0);
	assert(getPrimesCount(6538291, 9329325) == 175791);
	assert(findNextPrime(9072582) == 9072587);

	//test #322
	assert(isPrime(9500963) == 1);
	assert(getPrimesCount(3553709, 5285281) == 113288);
	assert(findNextPrime(9500963) == 9500963);

	//test #323
	assert(isPrime(2154838) == 0);
	assert(getPrimesCount(4985951, 5999659) == 65233);
	assert(findNextPrime(2154838) == 2154839);

	//test #324
	assert(isPrime(3012396) == 0);
	assert(getPrimesCount(2331143, 4816207) == 164890);
	assert(findNextPrime(3012396) == 3012409);

	//test #325
	assert(isPrime(5605722) == 0);
	assert(getPrimesCount(2702648, 5600836) == 190436);
	assert(findNextPrime(5605722) == 5605739);

	//test #326
	assert(isPrime(9480582) == 0);
	assert(getPrimesCount(7644976, 8865859) == 76665);
	assert(findNextPrime(9480582) == 9480589);

	//test #327
	assert(isPrime(4088798) == 0);
	assert(getPrimesCount(7455181, 7519515) == 4022);
	assert(findNextPrime(4088798) == 4088801);

	//test #328
	assert(isPrime(7238088) == 0);
	assert(getPrimesCount(1129318, 1980817) == 59758);
	assert(findNextPrime(7238088) == 7238089);

	//test #329
	assert(isPrime(4959416) == 0);
	assert(getPrimesCount(261407, 5499765) == 357837);
	assert(findNextPrime(4959416) == 4959419);

	//test #330
	assert(isPrime(8428806) == 0);
	assert(getPrimesCount(6466911, 8686568) == 140210);
	assert(findNextPrime(8428806) == 8428811);

	//test #331
	assert(isPrime(8994678) == 0);
	assert(getPrimesCount(497831, 4462786) == 272137);
	assert(findNextPrime(8994678) == 8994707);

	//test #332
	assert(isPrime(3120579) == 0);
	assert(getPrimesCount(2172208, 7431272) == 343163);
	assert(findNextPrime(3120579) == 3120589);

	//test #333
	assert(isPrime(5279659) == 0);
	assert(getPrimesCount(3935863, 5259790) == 86332);
	assert(findNextPrime(5279659) == 5279671);

	//test #334
	assert(isPrime(1677738) == 0);
	assert(getPrimesCount(5255217, 5496969) == 15570);
	assert(findNextPrime(1677738) == 1677743);

	//test #335
	assert(isPrime(7967894) == 0);
	assert(getPrimesCount(5764305, 7520445) == 111803);
	assert(findNextPrime(7967894) == 7967909);

	//test #336
	assert(isPrime(4935321) == 0);
	assert(getPrimesCount(2675159, 6320988) == 238467);
	assert(findNextPrime(4935321) == 4935323);

	//test #337
	assert(isPrime(6078661) == 0);
	assert(getPrimesCount(3169778, 8335136) == 332637);
	assert(findNextPrime(6078661) == 6078679);

	//test #338
	assert(isPrime(5330643) == 0);
	assert(getPrimesCount(31010, 3151764) == 223613);
	assert(findNextPrime(5330643) == 5330657);

	//test #339
	assert(isPrime(673394) == 0);
	assert(getPrimesCount(4757870, 6251484) == 96194);
	assert(findNextPrime(673394) == 673397);

	//test #340
	assert(isPrime(5257430) == 0);
	assert(getPrimesCount(1176090, 3305807) == 146081);
	assert(findNextPrime(5257430) == 5257451);

	//test #341
	assert(isPrime(8817143) == 0);
	assert(getPrimesCount(4205243, 4462568) == 16827);
	assert(findNextPrime(8817143) == 8817163);

	//test #342
	assert(isPrime(9079122) == 0);
	assert(getPrimesCount(6469452, 8565353) == 132419);
	assert(findNextPrime(9079122) == 9079151);

	//test #343
	assert(isPrime(4801750) == 0);
	assert(getPrimesCount(2255648, 2418130) == 11069);
	assert(findNextPrime(4801750) == 4801781);

	//test #344
	assert(isPrime(2980045) == 0);
	assert(getPrimesCount(1243453, 4489496) == 219297);
	assert(findNextPrime(2980045) == 2980051);

	//test #345
	assert(isPrime(8085243) == 0);
	assert(getPrimesCount(1423699, 4465481) == 204932);
	assert(findNextPrime(8085243) == 8085257);

	//test #346
	assert(isPrime(4082310) == 0);
	assert(getPrimesCount(2927659, 8203453) == 340571);
	assert(findNextPrime(4082310) == 4082311);

	//test #347
	assert(isPrime(8482361) == 0);
	assert(getPrimesCount(4993709, 6538296) == 99086);
	assert(findNextPrime(8482361) == 8482373);

	//test #348
	assert(isPrime(7112312) == 0);
	assert(getPrimesCount(2475334, 7457513) == 324209);
	assert(findNextPrime(7112312) == 7112351);

	//test #349
	assert(isPrime(1724535) == 0);
	assert(getPrimesCount(1024589, 8261254) == 475864);
	assert(findNextPrime(1724535) == 1724537);

	//test #350
	assert(isPrime(3166416) == 0);
	assert(getPrimesCount(2951356, 9138781) == 397533);
	assert(findNextPrime(3166416) == 3166439);

	//test #351
	assert(isPrime(137019) == 0);
	assert(getPrimesCount(460974, 5742826) == 357832);
	assert(findNextPrime(137019) == 137029);

	//test #352
	assert(isPrime(7029968) == 0);
	assert(getPrimesCount(830994, 6041663) == 349283);
	assert(findNextPrime(7029968) == 7030013);

	//test #353
	assert(isPrime(746208) == 0);
	assert(getPrimesCount(2278793, 3607774) == 89173);
	assert(findNextPrime(746208) == 746209);

	//test #354
	assert(isPrime(3107951) == 0);
	assert(getPrimesCount(1213704, 2872614) == 114395);
	assert(findNextPrime(3107951) == 3107971);

	//test #355
	assert(isPrime(8646391) == 0);
	assert(getPrimesCount(4078338, 5668597) == 103224);
	assert(findNextPrime(8646391) == 8646401);

	//test #356
	assert(isPrime(8561166) == 0);
	assert(getPrimesCount(2195103, 7318421) == 334480);
	assert(findNextPrime(8561166) == 8561213);

	//test #357
	assert(isPrime(2509527) == 0);
	assert(getPrimesCount(6492753, 8688320) == 138683);
	assert(findNextPrime(2509527) == 2509531);

	//test #358
	assert(isPrime(5060332) == 0);
	assert(getPrimesCount(1349546, 3498891) == 146551);
	assert(findNextPrime(5060332) == 5060333);

	//test #359
	assert(isPrime(9504547) == 0);
	assert(getPrimesCount(3138613, 6374709) == 210733);
	assert(findNextPrime(9504547) == 9504559);

	//test #360
	assert(isPrime(3770706) == 0);
	assert(getPrimesCount(2462371, 6143094) == 241475);
	assert(findNextPrime(3770706) == 3770717);

	//test #361
	assert(isPrime(5511437) == 0);
	assert(getPrimesCount(2934536, 2946628) == 812);
	assert(findNextPrime(5511437) == 5511461);

	//test #362
	assert(isPrime(2719434) == 0);
	assert(getPrimesCount(4072701, 4101162) == 1887);
	assert(findNextPrime(2719434) == 2719447);

	//test #363
	assert(isPrime(6431920) == 0);
	assert(getPrimesCount(3494028, 8149932) == 299387);
	assert(findNextPrime(6431920) == 6431951);

	//test #364
	assert(isPrime(4686700) == 0);
	assert(getPrimesCount(56689, 4504666) == 310513);
	assert(findNextPrime(4686700) == 4686701);

	//test #365
	assert(isPrime(8614718) == 0);
	assert(getPrimesCount(2236115, 4442508) == 147029);
	assert(findNextPrime(8614718) == 8614729);

	//test #366
	assert(isPrime(7526994) == 0);
	assert(getPrimesCount(2501613, 8852836) == 410111);
	assert(findNextPrime(7526994) == 7527011);

	//test #367
	assert(isPrime(3342459) == 0);
	assert(getPrimesCount(5532424, 9733624) == 265302);
	assert(findNextPrime(3342459) == 3342473);

	//test #368
	assert(isPrime(2713546) == 0);
	assert(getPrimesCount(5933806, 6710380) == 49529);
	assert(findNextPrime(2713546) == 2713553);

	//test #369
	assert(isPrime(3630862) == 0);
	assert(getPrimesCount(2676942, 6587758) == 255313);
	assert(findNextPrime(3630862) == 3630883);

	//test #370
	assert(isPrime(6278383) == 0);
	assert(getPrimesCount(446883, 3888063) == 238336);
	assert(findNextPrime(6278383) == 6278407);

	//test #371
	assert(isPrime(9676712) == 0);
	assert(getPrimesCount(952810, 6545846) == 372577);
	assert(findNextPrime(9676712) == 9676717);

	//test #372
	assert(isPrime(8562713) == 0);
	assert(getPrimesCount(2617108, 4860365) == 148341);
	assert(findNextPrime(8562713) == 8562737);

	//test #373
	assert(isPrime(216714) == 0);
	assert(getPrimesCount(6850489, 7366314) == 32753);
	assert(findNextPrime(216714) == 216719);

	//test #374
	assert(isPrime(5805445) == 0);
	assert(getPrimesCount(4093771, 8951854) == 310119);
	assert(findNextPrime(5805445) == 5805467);

	//test #375
	assert(isPrime(6130257) == 0);
	assert(getPrimesCount(6604117, 7566280) == 61014);
	assert(findNextPrime(6130257) == 6130261);

	//test #376
	assert(isPrime(2413453) == 0);
	assert(getPrimesCount(1250742, 2251995) == 69688);
	assert(findNextPrime(2413453) == 2413469);

	//test #377
	assert(isPrime(8290471) == 0);
	assert(getPrimesCount(3766555, 8918798) == 329598);
	assert(findNextPrime(8290471) == 8290481);

	//test #378
	assert(isPrime(5486055) == 0);
	assert(getPrimesCount(3981276, 7291251) == 213160);
	assert(findNextPrime(5486055) == 5486057);

	//test #379
	assert(isPrime(1577660) == 0);
	assert(getPrimesCount(5209466, 6538540) == 85190);
	assert(findNextPrime(1577660) == 1577663);

	//test #380
	assert(isPrime(8137483) == 0);
	assert(getPrimesCount(4220602, 6123840) == 123110);
	assert(findNextPrime(8137483) == 8137501);

	//test #381
	assert(isPrime(1135376) == 0);
	assert(getPrimesCount(2847710, 4269746) == 94242);
	assert(findNextPrime(1135376) == 1135403);

	//test #382
	assert(isPrime(1468127) == 0);
	assert(getPrimesCount(6059152, 7584178) == 96892);
	assert(findNextPrime(1468127) == 1468163);

	//test #383
	assert(isPrime(3966650) == 0);
	assert(getPrimesCount(2085273, 8205793) == 397880);
	assert(findNextPrime(3966650) == 3966689);

	//test #384
	assert(isPrime(9904818) == 0);
	assert(getPrimesCount(615120, 1727998) == 79840);
	assert(findNextPrime(9904818) == 9904819);

	//test #385
	assert(isPrime(9426839) == 0);
	assert(getPrimesCount(3598867, 4486039) == 58391);
	assert(findNextPrime(9426839) == 9426853);

	//test #386
	assert(isPrime(2557713) == 0);
	assert(getPrimesCount(2456654, 8387215) == 383945);
	assert(findNextPrime(2557713) == 2557729);

	//test #387
	assert(isPrime(618680) == 0);
	assert(getPrimesCount(808312, 8207914) == 488271);
	assert(findNextPrime(618680) == 618703);

	//test #388
	assert(isPrime(9659897) == 0);
	assert(getPrimesCount(1024372, 4367081) == 226899);
	assert(findNextPrime(9659897) == 9659911);

	//test #389
	assert(isPrime(2164316) == 0);
	assert(getPrimesCount(2010036, 7692987) == 370822);
	assert(findNextPrime(2164316) == 2164367);

	//test #390
	assert(isPrime(2772145) == 0);
	assert(getPrimesCount(639961, 3580874) == 203379);
	assert(findNextPrime(2772145) == 2772179);

	//test #391
	assert(isPrime(131338) == 0);
	assert(getPrimesCount(1033286, 6872010) == 387565);
	assert(findNextPrime(131338) == 131357);

	//test #392
	assert(isPrime(1627505) == 0);
	assert(getPrimesCount(1057400, 5024987) == 267468);
	assert(findNextPrime(1627505) == 1627513);

	//test #393
	assert(isPrime(9651950) == 0);
	assert(getPrimesCount(2701583, 6479836) == 246719);
	assert(findNextPrime(9651950) == 9651959);

	//test #394
	assert(isPrime(2582275) == 0);
	assert(getPrimesCount(1508884, 3958172) == 165639);
	assert(findNextPrime(2582275) == 2582311);

	//test #395
	assert(isPrime(4009188) == 0);
	assert(getPrimesCount(3437444, 3943183) == 33394);
	assert(findNextPrime(4009188) == 4009193);

	//test #396
	assert(isPrime(1000281) == 0);
	assert(getPrimesCount(6214687, 8920422) == 170923);
	assert(findNextPrime(1000281) == 1000289);

	//test #397
	assert(isPrime(8482119) == 0);
	assert(getPrimesCount(3481053, 7217712) == 241519);
	assert(findNextPrime(8482119) == 8482169);

	//test #398
	assert(isPrime(5610984) == 0);
	assert(getPrimesCount(5309973, 5470758) == 10363);
	assert(findNextPrime(5610984) == 5610991);

	//test #399
	assert(isPrime(3038733) == 0);
	assert(getPrimesCount(4131090, 6561967) == 156946);
	assert(findNextPrime(3038733) == 3038741);

	//test #400
	assert(isPrime(3316795) == 0);
	assert(getPrimesCount(5175836, 8273441) == 197060);
	assert(findNextPrime(3316795) == 3316799);

	//test #401
	assert(isPrime(1167712) == 0);
	assert(getPrimesCount(4034141, 9348570) == 338795);
	assert(findNextPrime(1167712) == 1167731);

	//test #402
	assert(isPrime(9313295) == 0);
	assert(getPrimesCount(7905425, 9220328) == 82369);
	assert(findNextPrime(9313295) == 9313301);

	//test #403
	assert(isPrime(1259084) == 0);
	assert(getPrimesCount(1651327, 9534250) == 510994);
	assert(findNextPrime(1259084) == 1259087);

	//test #404
	assert(isPrime(1650594) == 0);
	assert(getPrimesCount(6220539, 6293036) == 4666);
	assert(findNextPrime(1650594) == 1650601);

	//test #405
	assert(isPrime(6765887) == 0);
	assert(getPrimesCount(6677441, 6929310) == 16058);
	assert(findNextPrime(6765887) == 6765893);

	//test #406
	assert(isPrime(3610632) == 0);
	assert(getPrimesCount(4448388, 5078256) == 40991);
	assert(findNextPrime(3610632) == 3610657);

	//test #407
	assert(isPrime(3804844) == 0);
	assert(getPrimesCount(4962291, 8965098) == 254253);
	assert(findNextPrime(3804844) == 3804859);

	//test #408
	assert(isPrime(3486148) == 0);
	assert(getPrimesCount(1535776, 9542577) == 519577);
	assert(findNextPrime(3486148) == 3486149);

	//test #409
	assert(isPrime(4529356) == 0);
	assert(getPrimesCount(3540570, 8211381) == 300248);
	assert(findNextPrime(4529356) == 4529359);

	//test #410
	assert(isPrime(4468434) == 0);
	assert(getPrimesCount(3083938, 9132364) == 388252);
	assert(findNextPrime(4468434) == 4468441);

	//test #411
	assert(isPrime(9666496) == 0);
	assert(getPrimesCount(3263772, 7133516) == 250621);
	assert(findNextPrime(9666496) == 9666533);

	//test #412
	assert(isPrime(7758159) == 0);
	assert(getPrimesCount(3256438, 5942977) == 175229);
	assert(findNextPrime(7758159) == 7758161);

	//test #413
	assert(isPrime(6718086) == 0);
	assert(getPrimesCount(456452, 887011) == 32145);
	assert(findNextPrime(6718086) == 6718087);

	//test #414
	assert(isPrime(2616465) == 0);
	assert(getPrimesCount(191101, 7852047) == 513213);
	assert(findNextPrime(2616465) == 2616469);

	//test #415
	assert(isPrime(4981970) == 0);
	assert(getPrimesCount(2058892, 8543929) == 420913);
	assert(findNextPrime(4981970) == 4981981);

	//test #416
	assert(isPrime(3441646) == 0);
	assert(getPrimesCount(447468, 8334257) == 523222);
	assert(findNextPrime(3441646) == 3441649);

	//test #417
	assert(isPrime(889770) == 0);
	assert(getPrimesCount(3743391, 6458247) == 175824);
	assert(findNextPrime(889770) == 889783);

	//test #418
	assert(isPrime(3481819) == 0);
	assert(getPrimesCount(6638506, 7848517) == 76644);
	assert(findNextPrime(3481819) == 3481823);

	//test #419
	assert(isPrime(9254434) == 0);
	assert(getPrimesCount(4839695, 5830061) == 63874);
	assert(findNextPrime(9254434) == 9254449);

	//test #420
	assert(isPrime(5979541) == 0);
	assert(getPrimesCount(3980703, 5638573) == 107748);
	assert(findNextPrime(5979541) == 5979551);

	//test #421
	assert(isPrime(7238236) == 0);
	assert(getPrimesCount(3659019, 8883870) == 334555);
	assert(findNextPrime(7238236) == 7238267);

	//test #422
	assert(isPrime(8190468) == 0);
	assert(getPrimesCount(872683, 5461857) == 309059);
	assert(findNextPrime(8190468) == 8190473);

	//test #423
	assert(isPrime(1257091) == 0);
	assert(getPrimesCount(769214, 2889405) == 147732);
	assert(findNextPrime(1257091) == 1257103);

	//test #424
	assert(isPrime(2664064) == 0);
	assert(getPrimesCount(3675358, 9170407) == 351323);
	assert(findNextPrime(2664064) == 2664071);

	//test #425
	assert(isPrime(9627847) == 0);
	assert(getPrimesCount(6299515, 6503259) == 12941);
	assert(findNextPrime(9627847) == 9627853);

	//test #426
	assert(isPrime(4133622) == 0);
	assert(getPrimesCount(5242368, 8802629) == 226008);
	assert(findNextPrime(4133622) == 4133639);

	//test #427
	assert(isPrime(8854310) == 0);
	assert(getPrimesCount(1485768, 9348602) == 511050);
	assert(findNextPrime(8854310) == 8854337);

	//test #428
	assert(isPrime(5172201) == 0);
	assert(getPrimesCount(457872, 6809107) == 426141);
	assert(findNextPrime(5172201) == 5172221);

	//test #429
	assert(isPrime(7437002) == 0);
	assert(getPrimesCount(4437999, 8593804) == 265193);
	assert(findNextPrime(7437002) == 7437029);

	//test #430
	assert(isPrime(8059162) == 0);
	assert(getPrimesCount(4998200, 6232443) == 79312);
	assert(findNextPrime(8059162) == 8059169);

	//test #431
	assert(isPrime(2287593) == 0);
	assert(getPrimesCount(3030418, 7799521) == 308281);
	assert(findNextPrime(2287593) == 2287613);

	//test #432
	assert(isPrime(5627091) == 0);
	assert(getPrimesCount(6665549, 6948671) == 18076);
	assert(findNextPrime(5627091) == 5627099);

	//test #433
	assert(isPrime(458884) == 0);
	assert(getPrimesCount(2815736, 7874632) == 327450);
	assert(findNextPrime(458884) == 458891);

	//test #434
	assert(isPrime(7157961) == 0);
	assert(getPrimesCount(1995312, 6369513) == 287903);
	assert(findNextPrime(7157961) == 7157963);

	//test #435
	assert(isPrime(5589482) == 0);
	assert(getPrimesCount(6041024, 6364897) == 20721);
	assert(findNextPrime(5589482) == 5589497);

	//test #436
	assert(isPrime(5090767) == 0);
	assert(getPrimesCount(3548709, 7644808) == 264070);
	assert(findNextPrime(5090767) == 5090773);

	//test #437
	assert(isPrime(9612893) == 0);
	assert(getPrimesCount(8699457, 9924119) == 76239);
	assert(findNextPrime(9612893) == 9612899);

	//test #438
	assert(isPrime(4506952) == 0);
	assert(getPrimesCount(1144128, 4246555) == 210470);
	assert(findNextPrime(4506952) == 4506973);

	//test #439
	assert(isPrime(3607414) == 0);
	assert(getPrimesCount(2563056, 8428938) == 379338);
	assert(findNextPrime(3607414) == 3607421);

	//test #440
	assert(isPrime(5130301) == 0);
	assert(getPrimesCount(7094084, 7971703) == 55349);
	assert(findNextPrime(5130301) == 5130331);

	//test #441
	assert(isPrime(2500469) == 0);
	assert(getPrimesCount(3914350, 9826248) == 376358);
	assert(findNextPrime(2500469) == 2500523);

	//test #442
	assert(isPrime(5674111) == 0);
	assert(getPrimesCount(2628542, 8047104) == 350950);
	assert(findNextPrime(5674111) == 5674117);

	//test #443
	assert(isPrime(1406247) == 0);
	assert(getPrimesCount(1277606, 6260962) == 331093);
	assert(findNextPrime(1406247) == 1406267);

	//test #444
	assert(isPrime(4193229) == 0);
	assert(getPrimesCount(87242, 3104631) == 215330);
	assert(findNextPrime(4193229) == 4193239);

	//test #445
	assert(isPrime(7628351) == 0);
	assert(getPrimesCount(303666, 3479010) == 222488);
	assert(findNextPrime(7628351) == 7628377);

	//test #446
	assert(isPrime(6780552) == 0);
	assert(getPrimesCount(4530356, 4949149) == 27272);
	assert(findNextPrime(6780552) == 6780581);

	//test #447
	assert(isPrime(6574081) == 1);
	assert(getPrimesCount(3540515, 6170222) == 170972);
	assert(findNextPrime(6574081) == 6574081);

	//test #448
	assert(isPrime(708284) == 0);
	assert(getPrimesCount(6442997, 9711475) == 205643);
	assert(findNextPrime(708284) == 708287);

	//test #449
	assert(isPrime(8101088) == 0);
	assert(getPrimesCount(4296039, 9032334) == 301883);
	assert(findNextPrime(8101088) == 8101097);

	//test #450
	assert(isPrime(7596817) == 0);
	assert(getPrimesCount(2182857, 2547493) == 24779);
	assert(findNextPrime(7596817) == 7596833);

	//test #451
	assert(isPrime(2924460) == 0);
	assert(getPrimesCount(5760961, 6815850) == 67370);
	assert(findNextPrime(2924460) == 2924477);

	//test #452
	assert(isPrime(4216002) == 0);
	assert(getPrimesCount(1473525, 8144097) == 436495);
	assert(findNextPrime(4216002) == 4216007);

	//test #453
	assert(isPrime(2019624) == 0);
	assert(getPrimesCount(279539, 6941232) == 448509);
	assert(findNextPrime(2019624) == 2019659);

	//test #454
	assert(isPrime(5794675) == 0);
	assert(getPrimesCount(2906627, 6594750) == 240266);
	assert(findNextPrime(5794675) == 5794697);

	//test #455
	assert(isPrime(7971423) == 0);
	assert(getPrimesCount(5654033, 9332375) == 232541);
	assert(findNextPrime(7971423) == 7971443);

	//test #456
	assert(isPrime(1368540) == 0);
	assert(getPrimesCount(1150192, 5344984) == 281496);
	assert(findNextPrime(1368540) == 1368547);

	//test #457
	assert(isPrime(6919258) == 0);
	assert(getPrimesCount(5321614, 5860613) == 34593);
	assert(findNextPrime(6919258) == 6919261);

	//test #458
	assert(isPrime(4270546) == 0);
	assert(getPrimesCount(7332495, 9315362) == 124429);
	assert(findNextPrime(4270546) == 4270559);

	//test #459
	assert(isPrime(6233247) == 0);
	assert(getPrimesCount(455324, 6961752) == 436113);
	assert(findNextPrime(6233247) == 6233257);

	//test #460
	assert(isPrime(4861030) == 0);
	assert(getPrimesCount(6455943, 8606150) == 135861);
	assert(findNextPrime(4861030) == 4861033);

	//test #461
	assert(isPrime(7117452) == 0);
	assert(getPrimesCount(1210556, 8292199) == 464464);
	assert(findNextPrime(7117452) == 7117459);

	//test #462
	assert(isPrime(8582285) == 0);
	assert(getPrimesCount(3118970, 6432909) == 215709);
	assert(findNextPrime(8582285) == 8582293);

	//test #463
	assert(isPrime(5705361) == 0);
	assert(getPrimesCount(5423757, 9604089) == 264217);
	assert(findNextPrime(5705361) == 5705417);

	//test #464
	assert(isPrime(5589116) == 0);
	assert(getPrimesCount(7944527, 9882377) == 121055);
	assert(findNextPrime(5589116) == 5589127);

	//test #465
	assert(isPrime(212776) == 0);
	assert(getPrimesCount(393784, 8641679) == 546685);
	assert(findNextPrime(212776) == 212777);

	//test #466
	assert(isPrime(3117943) == 1);
	assert(getPrimesCount(6611483, 7257626) == 41067);
	assert(findNextPrime(3117943) == 3117943);

	//test #467
	assert(isPrime(770283) == 0);
	assert(getPrimesCount(3334970, 4472498) == 74917);
	assert(findNextPrime(770283) == 770291);

	//test #468
	assert(isPrime(5330419) == 0);
	assert(getPrimesCount(6569664, 7738412) == 74100);
	assert(findNextPrime(5330419) == 5330443);

	//test #469
	assert(isPrime(2081934) == 0);
	assert(getPrimesCount(2521652, 6847775) == 282394);
	assert(findNextPrime(2081934) == 2081969);

	//test #470
	assert(isPrime(6874188) == 0);
	assert(getPrimesCount(2231745, 4170023) == 129509);
	assert(findNextPrime(6874188) == 6874201);

	//test #471
	assert(isPrime(6561533) == 0);
	assert(getPrimesCount(4442205, 6043997) == 103525);
	assert(findNextPrime(6561533) == 6561539);

	//test #472
	assert(isPrime(7116955) == 0);
	assert(getPrimesCount(6569121, 9220161) == 166993);
	assert(findNextPrime(7116955) == 7116983);

	//test #473
	assert(isPrime(8833875) == 0);
	assert(getPrimesCount(2287654, 9674835) == 475847);
	assert(findNextPrime(8833875) == 8833889);

	//test #474
	assert(isPrime(2551617) == 0);
	assert(getPrimesCount(3714840, 5640865) == 125434);
	assert(findNextPrime(2551617) == 2551639);

	//test #475
	assert(isPrime(8952185) == 0);
	assert(getPrimesCount(6660205, 9458653) == 176047);
	assert(findNextPrime(8952185) == 8952193);

	//test #476
	assert(isPrime(8477660) == 0);
	assert(getPrimesCount(9632168, 9854366) == 13768);
	assert(findNextPrime(8477660) == 8477671);

	//test #477
	assert(isPrime(7447241) == 0);
	assert(getPrimesCount(4143354, 7556013) == 219228);
	assert(findNextPrime(7447241) == 7447243);

	//test #478
	assert(isPrime(7738654) == 0);
	assert(getPrimesCount(6159109, 7765875) == 101997);
	assert(findNextPrime(7738654) == 7738663);

	//test #479
	assert(isPrime(2930568) == 0);
	assert(getPrimesCount(5437256, 8518982) == 195572);
	assert(findNextPrime(2930568) == 2930593);

	//test #480
	assert(isPrime(722997) == 0);
	assert(getPrimesCount(1934490, 7218345) == 346053);
	assert(findNextPrime(722997) == 723029);

	//test #481
	assert(isPrime(668163) == 0);
	assert(getPrimesCount(729010, 1290739) == 40670);
	assert(findNextPrime(668163) == 668179);

	//test #482
	assert(isPrime(5725249) == 0);
	assert(getPrimesCount(4182350, 7447451) == 209824);
	assert(findNextPrime(5725249) == 5725253);

	//test #483
	assert(isPrime(7976228) == 0);
	assert(getPrimesCount(7233529, 8111272) == 55288);
	assert(findNextPrime(7976228) == 7976231);

	//test #484
	assert(isPrime(5168812) == 0);
	assert(getPrimesCount(1575279, 6316798) == 313713);
	assert(findNextPrime(5168812) == 5168837);

	//test #485
	assert(isPrime(2638157) == 0);
	assert(getPrimesCount(3732185, 3788193) == 3654);
	assert(findNextPrime(2638157) == 2638177);

	//test #486
	assert(isPrime(1063848) == 0);
	assert(getPrimesCount(4279979, 7849404) == 228765);
	assert(findNextPrime(1063848) == 1063849);

	//test #487
	assert(isPrime(3802645) == 0);
	assert(getPrimesCount(2327341, 6411130) == 267769);
	assert(findNextPrime(3802645) == 3802649);

	//test #488
	assert(isPrime(6814887) == 0);
	assert(getPrimesCount(5028797, 9527423) == 284928);
	assert(findNextPrime(6814887) == 6814889);

	//test #489
	assert(isPrime(1324077) == 0);
	assert(getPrimesCount(403975, 6932195) == 438162);
	assert(findNextPrime(1324077) == 1324093);

	//test #490
	assert(isPrime(4266862) == 0);
	assert(getPrimesCount(6640935, 7958445) == 83395);
	assert(findNextPrime(4266862) == 4266893);

	//test #491
	assert(isPrime(381212) == 0);
	assert(getPrimesCount(6407419, 6415117) == 480);
	assert(findNextPrime(381212) == 381221);

	//test #492
	assert(isPrime(7940597) == 0);
	assert(getPrimesCount(4184213, 5744001) == 101167);
	assert(findNextPrime(7940597) == 7940627);

	//test #493
	assert(isPrime(638306) == 0);
	assert(getPrimesCount(3504440, 5740529) == 145769);
	assert(findNextPrime(638306) == 638317);

	//test #494
	assert(isPrime(4111420) == 0);
	assert(getPrimesCount(5949612, 9768136) == 240629);
	assert(findNextPrime(4111420) == 4111423);

	//test #495
	assert(isPrime(1226471) == 1);
	assert(getPrimesCount(47512, 5396424) == 369226);
	assert(findNextPrime(1226471) == 1226471);

	//test #496
	assert(isPrime(3197331) == 0);
	assert(getPrimesCount(3271319, 7742560) == 288569);
	assert(findNextPrime(3197331) == 3197353);

	//test #497
	assert(isPrime(1787108) == 0);
	assert(getPrimesCount(1107173, 3436186) == 159722);
	assert(findNextPrime(1787108) == 1787129);

	//test #498
	assert(isPrime(4904764) == 0);
	assert(getPrimesCount(2193971, 8771456) == 425943);
	assert(findNextPrime(4904764) == 4904777);

	//test #499
	assert(isPrime(6039180) == 0);
	assert(getPrimesCount(793540, 7202750) == 426028);
	assert(findNextPrime(6039180) == 6039193);

	//test #500
	assert(isPrime(2782090) == 0);
	assert(getPrimesCount(1083198, 7230849) == 406753);
	assert(findNextPrime(2782090) == 2782097);

	//test #501
	assert(isPrime(9556246) == 0);
	assert(getPrimesCount(1823541, 4194135) == 159235);
	assert(findNextPrime(9556246) == 9556291);

	//test #502
	assert(isPrime(5749353) == 0);
	assert(getPrimesCount(2660964, 5582659) == 192063);
	assert(findNextPrime(5749353) == 5749361);

	//test #503
	assert(isPrime(5490396) == 0);
	assert(getPrimesCount(6086371, 9414484) == 209951);
	assert(findNextPrime(5490396) == 5490409);

	//test #504
	assert(isPrime(4672558) == 0);
	assert(getPrimesCount(5680956, 6191151) == 32715);
	assert(findNextPrime(4672558) == 4672561);

	//test #505
	assert(isPrime(6557919) == 0);
	assert(getPrimesCount(3852241, 5636960) == 116108);
	assert(findNextPrime(6557919) == 6557939);

	//test #506
	assert(isPrime(6059523) == 0);
	assert(getPrimesCount(1127274, 8103963) == 458585);
	assert(findNextPrime(6059523) == 6059549);

	//test #507
	assert(isPrime(1490598) == 0);
	assert(getPrimesCount(242322, 9078435) == 585898);
	assert(findNextPrime(1490598) == 1490603);

	//test #508
	assert(isPrime(1910495) == 0);
	assert(getPrimesCount(2310317, 3907055) == 106838);
	assert(findNextPrime(1910495) == 1910509);

	//test #509
	assert(isPrime(6339375) == 0);
	assert(getPrimesCount(3078531, 7615802) == 293522);
	assert(findNextPrime(6339375) == 6339391);

	//test #510
	assert(isPrime(8825998) == 0);
	assert(getPrimesCount(266528, 1240769) == 72445);
	assert(findNextPrime(8825998) == 8826011);

	//test #511
	assert(isPrime(578433) == 0);
	assert(getPrimesCount(9306565, 9659201) == 21941);
	assert(findNextPrime(578433) == 578441);

	//test #512
	assert(isPrime(1405464) == 0);
	assert(getPrimesCount(1265085, 4359344) == 209143);
	assert(findNextPrime(1405464) == 1405477);

	//test #513
	assert(isPrime(150997) == 0);
	assert(getPrimesCount(135886, 8391534) == 551698);
	assert(findNextPrime(150997) == 151007);

	//test #514
	assert(isPrime(4988718) == 0);
	assert(getPrimesCount(8647826, 9988740) == 83465);
	assert(findNextPrime(4988718) == 4988719);

	//test #515
	assert(isPrime(3143675) == 0);
	assert(getPrimesCount(6188941, 7367759) == 75009);
	assert(findNextPrime(3143675) == 3143711);

	//test #516
	assert(isPrime(5497663) == 1);
	assert(getPrimesCount(4309547, 5076098) == 49957);
	assert(findNextPrime(5497663) == 5497663);

	//test #517
	assert(isPrime(7414879) == 1);
	assert(getPrimesCount(118194, 7188869) == 477463);
	assert(findNextPrime(7414879) == 7414879);

	//test #518
	assert(isPrime(1587687) == 0);
	assert(getPrimesCount(4324906, 5359612) == 67303);
	assert(findNextPrime(1587687) == 1587701);

	//test #519
	assert(isPrime(4891755) == 0);
	assert(getPrimesCount(7676211, 9115155) == 90217);
	assert(findNextPrime(4891755) == 4891763);

	//test #520
	assert(isPrime(3276819) == 0);
	assert(getPrimesCount(912600, 8315173) == 487351);
	assert(findNextPrime(3276819) == 3276821);

	//test #521
	assert(isPrime(6584311) == 1);
	assert(getPrimesCount(2076585, 4007102) == 129406);
	assert(findNextPrime(6584311) == 6584311);

	//test #522
	assert(isPrime(8252339) == 1);
	assert(getPrimesCount(3120894, 8663883) == 356564);
	assert(findNextPrime(8252339) == 8252339);

	//test #523
	assert(isPrime(3765971) == 0);
	assert(getPrimesCount(5175195, 8212098) == 193270);
	assert(findNextPrime(3765971) == 3765977);

	//test #524
	assert(isPrime(1547671) == 1);
	assert(getPrimesCount(1622597, 2291285) == 46199);
	assert(findNextPrime(1547671) == 1547671);

	//test #525
	assert(isPrime(7649363) == 0);
	assert(getPrimesCount(343941, 9690664) == 616000);
	assert(findNextPrime(7649363) == 7649377);

	//test #526
	assert(isPrime(7932897) == 0);
	assert(getPrimesCount(2543631, 4869428) == 153938);
	assert(findNextPrime(7932897) == 7932913);

	//test #527
	assert(isPrime(2316986) == 0);
	assert(getPrimesCount(4652424, 8654180) == 254995);
	assert(findNextPrime(2316986) == 2317009);

	//test #528
	assert(isPrime(8947364) == 0);
	assert(getPrimesCount(3270577, 9716559) == 412120);
	assert(findNextPrime(8947364) == 8947369);

	//test #529
	assert(isPrime(9388086) == 0);
	assert(getPrimesCount(3457487, 4305579) == 55794);
	assert(findNextPrime(9388086) == 9388091);

	//test #530
	assert(isPrime(9022409) == 0);
	assert(getPrimesCount(649879, 8316670) == 506832);
	assert(findNextPrime(9022409) == 9022411);

	//test #531
	assert(isPrime(500777) == 1);
	assert(getPrimesCount(2220198, 4355822) == 142427);
	assert(findNextPrime(500777) == 500777);

	//test #532
	assert(isPrime(6046135) == 0);
	assert(getPrimesCount(4499712, 8650766) == 264692);
	assert(findNextPrime(6046135) == 6046189);

	//test #533
	assert(isPrime(4553620) == 0);
	assert(getPrimesCount(90028, 7719751) == 513429);
	assert(findNextPrime(4553620) == 4553623);

	//test #534
	assert(isPrime(1170706) == 0);
	assert(getPrimesCount(9147610, 9160037) == 752);
	assert(findNextPrime(1170706) == 1170707);

	//test #535
	assert(isPrime(8588194) == 0);
	assert(getPrimesCount(8856492, 9885773) == 64041);
	assert(findNextPrime(8588194) == 8588207);

	//test #536
	assert(isPrime(565202) == 0);
	assert(getPrimesCount(4041468, 7184468) == 202417);
	assert(findNextPrime(565202) == 565207);

	//test #537
	assert(isPrime(6411841) == 0);
	assert(getPrimesCount(3725304, 9703271) == 381169);
	assert(findNextPrime(6411841) == 6411851);

	//test #538
	assert(isPrime(120088) == 0);
	assert(getPrimesCount(1092379, 2764642) == 115824);
	assert(findNextPrime(120088) == 120091);

	//test #539
	assert(isPrime(2196385) == 0);
	assert(getPrimesCount(888192, 5821143) == 330935);
	assert(findNextPrime(2196385) == 2196401);

	//test #540
	assert(isPrime(7383040) == 0);
	assert(getPrimesCount(1174267, 4143078) == 201488);
	assert(findNextPrime(7383040) == 7383041);

	//test #541
	assert(isPrime(661697) == 1);
	assert(getPrimesCount(569624, 1247894) == 49523);
	assert(findNextPrime(661697) == 661697);

	//test #542
	assert(isPrime(8185423) == 0);
	assert(getPrimesCount(7207337, 8496718) == 81133);
	assert(findNextPrime(8185423) == 8185433);

	//test #543
	assert(isPrime(8620019) == 0);
	assert(getPrimesCount(266188, 3151874) == 203635);
	assert(findNextPrime(8620019) == 8620043);

	//test #544
	assert(isPrime(9263) == 0);
	assert(getPrimesCount(6331738, 7890105) == 98766);
	assert(findNextPrime(9263) == 9277);

	//test #545
	assert(isPrime(8247372) == 0);
	assert(getPrimesCount(2998086, 5343865) == 154060);
	assert(findNextPrime(8247372) == 8247373);

	//test #546
	assert(isPrime(243044) == 0);
	assert(getPrimesCount(118402, 8533142) == 562062);
	assert(findNextPrime(243044) == 243073);

	//test #547
	assert(isPrime(6965417) == 1);
	assert(getPrimesCount(2239866, 7375467) == 335035);
	assert(findNextPrime(6965417) == 6965417);

	//test #548
	assert(isPrime(3349673) == 1);
	assert(getPrimesCount(3427863, 7611255) == 269888);
	assert(findNextPrime(3349673) == 3349673);

	//test #549
	assert(isPrime(2053353) == 0);
	assert(getPrimesCount(4007579, 8448624) == 284238);
	assert(findNextPrime(2053353) == 2053357);

	//test #550
	assert(isPrime(8546982) == 0);
	assert(getPrimesCount(1661953, 6476570) == 317800);
	assert(findNextPrime(8546982) == 8546999);

	//test #551
	assert(isPrime(9443473) == 0);
	assert(getPrimesCount(1114553, 1148119) == 2387);
	assert(findNextPrime(9443473) == 9443479);

	//test #552
	assert(isPrime(3742823) == 0);
	assert(getPrimesCount(2572415, 8517583) == 384256);
	assert(findNextPrime(3742823) == 3742841);

	//test #553
	assert(isPrime(5731272) == 0);
	assert(getPrimesCount(2944797, 5635077) == 176336);
	assert(findNextPrime(5731272) == 5731277);

	//test #554
	assert(isPrime(3239602) == 0);
	assert(getPrimesCount(832844, 6949250) == 407035);
	assert(findNextPrime(3239602) == 3239603);

	//test #555
	assert(isPrime(8575015) == 0);
	assert(getPrimesCount(2016022, 6033258) == 264953);
	assert(findNextPrime(8575015) == 8575031);

	//test #556
	assert(isPrime(4652945) == 0);
	assert(getPrimesCount(1987452, 9390598) == 478775);
	assert(findNextPrime(4652945) == 4652957);

	//test #557
	assert(isPrime(9509714) == 0);
	assert(getPrimesCount(4487701, 8464214) == 253708);
	assert(findNextPrime(9509714) == 9509719);

	//test #558
	assert(isPrime(9150866) == 0);
	assert(getPrimesCount(3251270, 6102083) == 185724);
	assert(findNextPrime(9150866) == 9150871);

	//test #559
	assert(isPrime(4399363) == 1);
	assert(getPrimesCount(439534, 4809343) == 299158);
	assert(findNextPrime(4399363) == 4399363);

	//test #560
	assert(isPrime(3166354) == 0);
	assert(getPrimesCount(7259139, 7940293) == 42970);
	assert(findNextPrime(3166354) == 3166357);

	//test #561
	assert(isPrime(1370919) == 0);
	assert(getPrimesCount(2921344, 5587409) == 174835);
	assert(findNextPrime(1370919) == 1370921);

	//test #562
	assert(isPrime(5371718) == 0);
	assert(getPrimesCount(621379, 5397101) == 323455);
	assert(findNextPrime(5371718) == 5371727);

	//test #563
	assert(isPrime(4515765) == 0);
	assert(getPrimesCount(139589, 6773461) == 449233);
	assert(findNextPrime(4515765) == 4515767);

	//test #564
	assert(isPrime(5252215) == 0);
	assert(getPrimesCount(204501, 5896255) == 387854);
	assert(findNextPrime(5252215) == 5252231);

	//test #565
	assert(isPrime(5738365) == 0);
	assert(getPrimesCount(6591000, 8842075) == 142032);
	assert(findNextPrime(5738365) == 5738377);

	//test #566
	assert(isPrime(1854517) == 0);
	assert(getPrimesCount(3591791, 6990771) == 219881);
	assert(findNextPrime(1854517) == 1854527);

	//test #567
	assert(isPrime(4873773) == 0);
	assert(getPrimesCount(4832326, 9330824) == 285544);
	assert(findNextPrime(4873773) == 4873777);

	//test #568
	assert(isPrime(3871481) == 1);
	assert(getPrimesCount(455935, 6320033) == 395197);
	assert(findNextPrime(3871481) == 3871481);

	//test #569
	assert(isPrime(1320892) == 0);
	assert(getPrimesCount(780577, 5658312) == 328402);
	assert(findNextPrime(1320892) == 1320901);

	//test #570
	assert(isPrime(3991922) == 0);
	assert(getPrimesCount(4643564, 8503370) == 246061);
	assert(findNextPrime(3991922) == 3991943);

	//test #571
	assert(isPrime(2412213) == 0);
	assert(getPrimesCount(7085469, 7551662) == 29432);
	assert(findNextPrime(2412213) == 2412233);

	//test #572
	assert(isPrime(2258971) == 0);
	assert(getPrimesCount(3099425, 9078223) == 383839);
	assert(findNextPrime(2258971) == 2258981);

	//test #573
	assert(isPrime(9159260) == 0);
	assert(getPrimesCount(1289346, 6293293) == 332330);
	assert(findNextPrime(9159260) == 9159263);

	//test #574
	assert(isPrime(8892539) == 0);
	assert(getPrimesCount(114434, 3841523) == 261930);
	assert(findNextPrime(8892539) == 8892553);

	//test #575
	assert(isPrime(9115487) == 0);
	assert(getPrimesCount(2646919, 5653156) == 197539);
	assert(findNextPrime(9115487) == 9115501);

	//test #576
	assert(isPrime(8887511) == 0);
	assert(getPrimesCount(399, 9134384) == 610716);
	assert(findNextPrime(8887511) == 8887513);

	//test #577
	assert(isPrime(9476390) == 0);
	assert(getPrimesCount(2936511, 3647158) == 47333);
	assert(findNextPrime(9476390) == 9476393);

	//test #578
	assert(isPrime(2334461) == 0);
	assert(getPrimesCount(2607203, 7840735) == 339385);
	assert(findNextPrime(2334461) == 2334463);

	//test #579
	assert(isPrime(9284218) == 0);
	assert(getPrimesCount(2962728, 6095373) == 204637);
	assert(findNextPrime(9284218) == 9284237);

	//test #580
	assert(isPrime(5275937) == 0);
	assert(getPrimesCount(311168, 3328479) == 211913);
	assert(findNextPrime(5275937) == 5275987);

	//test #581
	assert(isPrime(116864) == 0);
	assert(getPrimesCount(3683183, 7575796) == 250753);
	assert(findNextPrime(116864) == 116867);

	//test #582
	assert(isPrime(9603666) == 0);
	assert(getPrimesCount(4676466, 8473234) == 241994);
	assert(findNextPrime(9603666) == 9603667);

	//test #583
	assert(isPrime(524340) == 0);
	assert(getPrimesCount(4986095, 5630332) == 41523);
	assert(findNextPrime(524340) == 524341);

	//test #584
	assert(isPrime(3526402) == 0);
	assert(getPrimesCount(344791, 1536421) == 87154);
	assert(findNextPrime(3526402) == 3526427);

	//test #585
	assert(isPrime(4251445) == 0);
	assert(getPrimesCount(5108000, 6901509) == 114909);
	assert(findNextPrime(4251445) == 4251449);

	//test #586
	assert(isPrime(91248) == 0);
	assert(getPrimesCount(2033009, 4416955) == 159213);
	assert(findNextPrime(91248) == 91249);

	//test #587
	assert(isPrime(466180) == 0);
	assert(getPrimesCount(1221756, 9983366) == 569096);
	assert(findNextPrime(466180) == 466181);

	//test #588
	assert(isPrime(8714850) == 0);
	assert(getPrimesCount(6217246, 8741130) == 159572);
	assert(findNextPrime(8714850) == 8714857);

	//test #589
	assert(isPrime(6489804) == 0);
	assert(getPrimesCount(2211185, 6330990) == 270623);
	assert(findNextPrime(6489804) == 6489809);

	//test #590
	assert(isPrime(4475564) == 0);
	assert(getPrimesCount(6094109, 8805733) == 171500);
	assert(findNextPrime(4475564) == 4475567);

	//test #591
	assert(isPrime(2003079) == 0);
	assert(getPrimesCount(4756188, 9521098) == 302282);
	assert(findNextPrime(2003079) == 2003081);

	//test #592
	assert(isPrime(5115356) == 0);
	assert(getPrimesCount(6403339, 8696669) == 144892);
	assert(findNextPrime(5115356) == 5115367);

	//test #593
	assert(isPrime(2470093) == 0);
	assert(getPrimesCount(6721981, 8461968) == 109806);
	assert(findNextPrime(2470093) == 2470099);

	//test #594
	assert(isPrime(6064129) == 1);
	assert(getPrimesCount(864450, 7515743) == 440566);
	assert(findNextPrime(6064129) == 6064129);

	//test #595
	assert(isPrime(3920132) == 0);
	assert(getPrimesCount(6468, 8914251) == 596269);
	assert(findNextPrime(3920132) == 3920141);

	//test #596
	assert(isPrime(7044018) == 0);
	assert(getPrimesCount(3889247, 9160299) == 336535);
	assert(findNextPrime(7044018) == 7044019);

	//test #597
	assert(isPrime(2137055) == 0);
	assert(getPrimesCount(221947, 4782049) == 314513);
	assert(findNextPrime(2137055) == 2137073);

	//test #598
	assert(isPrime(4673533) == 0);
	assert(getPrimesCount(3063219, 8168048) == 329295);
	assert(findNextPrime(4673533) == 4673551);

	//test #599
	assert(isPrime(5721618) == 0);
	assert(getPrimesCount(2915653, 3022239) == 7143);
	assert(findNextPrime(5721618) == 5721619);

	//test #600
	assert(isPrime(4012903) == 0);
	assert(getPrimesCount(605072, 7189897) == 439189);
	assert(findNextPrime(4012903) == 4012927);

	//test #601
	assert(isPrime(2131631) == 0);
	assert(getPrimesCount(2899551, 8376919) == 353345);
	assert(findNextPrime(2131631) == 2131651);

	//test #602
	assert(isPrime(7553976) == 0);
	assert(getPrimesCount(865971, 2408823) == 108089);
	assert(findNextPrime(7553976) == 7553977);

	//test #603
	assert(isPrime(1715660) == 0);
	assert(getPrimesCount(4147086, 4840666) == 45294);
	assert(findNextPrime(1715660) == 1715683);

	//test #604
	assert(isPrime(9758419) == 0);
	assert(getPrimesCount(1091595, 7972466) == 452943);
	assert(findNextPrime(9758419) == 9758431);

	//test #605
	assert(isPrime(1760968) == 0);
	assert(getPrimesCount(1659655, 5218058) == 237276);
	assert(findNextPrime(1760968) == 1760981);

	//test #606
	assert(isPrime(5664927) == 0);
	assert(getPrimesCount(1093242, 3346331) == 154757);
	assert(findNextPrime(5664927) == 5664931);

	//test #607
	assert(isPrime(7251977) == 0);
	assert(getPrimesCount(646117, 4098326) == 237131);
	assert(findNextPrime(7251977) == 7251983);

	//test #608
	assert(isPrime(7333419) == 0);
	assert(getPrimesCount(1222757, 8106083) == 451856);
	assert(findNextPrime(7333419) == 7333423);

	//test #609
	assert(isPrime(753741) == 0);
	assert(getPrimesCount(242446, 8540297) == 552254);
	assert(findNextPrime(753741) == 753743);

	//test #610
	assert(isPrime(6498125) == 0);
	assert(getPrimesCount(6021142, 6407478) == 24661);
	assert(findNextPrime(6498125) == 6498161);

	//test #611
	assert(isPrime(5294314) == 0);
	assert(getPrimesCount(7717404, 8589757) == 54797);
	assert(findNextPrime(5294314) == 5294323);

	//test #612
	assert(isPrime(6835200) == 0);
	assert(getPrimesCount(1215169, 5895071) == 312109);
	assert(findNextPrime(6835200) == 6835201);

	//test #613
	assert(isPrime(8927721) == 0);
	assert(getPrimesCount(5001883, 8182119) == 202560);
	assert(findNextPrime(8927721) == 8927741);

	//test #614
	assert(isPrime(7487904) == 0);
	assert(getPrimesCount(969839, 9473481) == 555603);
	assert(findNextPrime(7487904) == 7487911);

	//test #615
	assert(isPrime(2871177) == 0);
	assert(getPrimesCount(682590, 8075899) == 489289);
	assert(findNextPrime(2871177) == 2871191);

	//test #616
	assert(isPrime(4431381) == 0);
	assert(getPrimesCount(6357050, 6657615) == 19096);
	assert(findNextPrime(4431381) == 4431443);

	//test #617
	assert(isPrime(9373728) == 0);
	assert(getPrimesCount(1097818, 5038320) == 265411);
	assert(findNextPrime(9373728) == 9373759);

	//test #618
	assert(isPrime(3306686) == 0);
	assert(getPrimesCount(3379189, 3557532) == 11752);
	assert(findNextPrime(3306686) == 3306701);

	//test #619
	assert(isPrime(8451960) == 0);
	assert(getPrimesCount(6651287, 9232144) == 162530);
	assert(findNextPrime(8451960) == 8451967);

	//test #620
	assert(isPrime(712918) == 0);
	assert(getPrimesCount(4305332, 4339900) == 2258);
	assert(findNextPrime(712918) == 712927);

	//test #621
	assert(isPrime(3742910) == 0);
	assert(getPrimesCount(3666389, 6276497) == 169391);
	assert(findNextPrime(3742910) == 3742919);

	//test #622
	assert(isPrime(2553515) == 0);
	assert(getPrimesCount(7498624, 9142355) == 103142);
	assert(findNextPrime(2553515) == 2553527);

	//test #623
	assert(isPrime(1041010) == 0);
	assert(getPrimesCount(5435203, 9365686) == 248667);
	assert(findNextPrime(1041010) == 1041041);

	//test #624
	assert(isPrime(7423576) == 0);
	assert(getPrimesCount(707773, 2864524) == 150620);
	assert(findNextPrime(7423576) == 7423607);

	//test #625
	assert(isPrime(8364451) == 0);
	assert(getPrimesCount(2580364, 5766163) == 209324);
	assert(findNextPrime(8364451) == 8364457);

	//test #626
	assert(isPrime(2254828) == 0);
	assert(getPrimesCount(5274278, 7513951) == 142877);
	assert(findNextPrime(2254828) == 2254831);

	//test #627
	assert(isPrime(3055680) == 0);
	assert(getPrimesCount(1318400, 4536062) == 216945);
	assert(findNextPrime(3055680) == 3055687);

	//test #628
	assert(isPrime(2971866) == 0);
	assert(getPrimesCount(7073268, 9192703) == 133142);
	assert(findNextPrime(2971866) == 2971873);

	//test #629
	assert(isPrime(538488) == 0);
	assert(getPrimesCount(3176068, 6487453) == 215363);
	assert(findNextPrime(538488) == 538511);

	//test #630
	assert(isPrime(7563737) == 0);
	assert(getPrimesCount(5592389, 6591764) == 63933);
	assert(findNextPrime(7563737) == 7563761);

	//test #631
	assert(isPrime(1103996) == 0);
	assert(getPrimesCount(4267907, 7088549) == 181528);
	assert(findNextPrime(1103996) == 1104017);

	//test #632
	assert(isPrime(4369125) == 0);
	assert(getPrimesCount(815344, 1330578) == 37111);
	assert(findNextPrime(4369125) == 4369133);

	//test #633
	assert(isPrime(4271055) == 0);
	assert(getPrimesCount(1105968, 4285689) == 215751);
	assert(findNextPrime(4271055) == 4271081);

	//test #634
	assert(isPrime(6482291) == 0);
	assert(getPrimesCount(1017600, 4049438) == 206658);
	assert(findNextPrime(6482291) == 6482299);

	//test #635
	assert(isPrime(7918108) == 0);
	assert(getPrimesCount(3648259, 6772208) == 202170);
	assert(findNextPrime(7918108) == 7918109);

	//test #636
	assert(isPrime(1713449) == 1);
	assert(getPrimesCount(4028599, 9322100) == 337505);
	assert(findNextPrime(1713449) == 1713449);

	//test #637
	assert(isPrime(5054115) == 0);
	assert(getPrimesCount(1873278, 7245741) == 352034);
	assert(findNextPrime(5054115) == 5054129);

	//test #638
	assert(isPrime(9882711) == 0);
	assert(getPrimesCount(3187844, 9833802) == 425000);
	assert(findNextPrime(9882711) == 9882731);

	//test #639
	assert(isPrime(889516) == 0);
	assert(getPrimesCount(2364104, 6615803) == 278345);
	assert(findNextPrime(889516) == 889519);

	//test #640
	assert(isPrime(4475724) == 0);
	assert(getPrimesCount(86719, 2934925) == 204019);
	assert(findNextPrime(4475724) == 4475747);

	//test #641
	assert(isPrime(1015262) == 0);
	assert(getPrimesCount(4546079, 6964669) == 155494);
	assert(findNextPrime(1015262) == 1015277);

	//test #642
	assert(isPrime(4209684) == 0);
	assert(getPrimesCount(6367541, 6557301) == 12029);
	assert(findNextPrime(4209684) == 4209719);

	//test #643
	assert(isPrime(4225906) == 0);
	assert(getPrimesCount(6473104, 9078907) == 164293);
	assert(findNextPrime(4225906) == 4225931);

	//test #644
	assert(isPrime(7403182) == 0);
	assert(getPrimesCount(8526256, 8526573) == 19);
	assert(findNextPrime(7403182) == 7403183);

	//test #645
	assert(isPrime(4255145) == 0);
	assert(getPrimesCount(6285320, 9480011) == 201231);
	assert(findNextPrime(4255145) == 4255157);

	//test #646
	assert(isPrime(777654) == 0);
	assert(getPrimesCount(6772085, 7988162) == 76937);
	assert(findNextPrime(777654) == 777661);

	//test #647
	assert(isPrime(3082320) == 0);
	assert(getPrimesCount(5789807, 8288241) == 158537);
	assert(findNextPrime(3082320) == 3082327);

	//test #648
	assert(isPrime(9961971) == 0);
	assert(getPrimesCount(4463603, 7737567) == 209692);
	assert(findNextPrime(9961971) == 9961981);

	//test #649
	assert(isPrime(5042918) == 0);
	assert(getPrimesCount(2181776, 5404287) == 213185);
	assert(findNextPrime(5042918) == 5042927);

	//test #650
	assert(isPrime(6857587) == 0);
	assert(getPrimesCount(1396582, 6844624) == 359877);
	assert(findNextPrime(6857587) == 6857593);

	//test #651
	assert(isPrime(661586) == 0);
	assert(getPrimesCount(231214, 6065904) == 396530);
	assert(findNextPrime(661586) == 661603);

	//test #652
	assert(isPrime(7012498) == 0);
	assert(getPrimesCount(5210852, 7814132) == 165946);
	assert(findNextPrime(7012498) == 7012507);

	//test #653
	assert(isPrime(5935258) == 0);
	assert(getPrimesCount(3775916, 8493537) == 302317);
	assert(findNextPrime(5935258) == 5935271);

	//test #654
	assert(isPrime(9868544) == 0);
	assert(getPrimesCount(2526218, 8104880) == 361459);
	assert(findNextPrime(9868544) == 9868553);

	//test #655
	assert(isPrime(5339943) == 0);
	assert(getPrimesCount(2797310, 5587078) == 183204);
	assert(findNextPrime(5339943) == 5339987);

	//test #656
	assert(isPrime(7348992) == 0);
	assert(getPrimesCount(132368, 2300992) == 157226);
	assert(findNextPrime(7348992) == 7349003);

	//test #657
	assert(isPrime(5410972) == 0);
	assert(getPrimesCount(546447, 6115036) == 375161);
	assert(findNextPrime(5410972) == 5410973);

	//test #658
	assert(isPrime(6597955) == 0);
	assert(getPrimesCount(5072029, 6349376) == 82061);
	assert(findNextPrime(6597955) == 6597967);

	//test #659
	assert(isPrime(4524053) == 1);
	assert(getPrimesCount(2484380, 4769743) == 151495);
	assert(findNextPrime(4524053) == 4524053);

	//test #660
	assert(isPrime(1222995) == 0);
	assert(getPrimesCount(267007, 7705419) == 497849);
	assert(findNextPrime(1222995) == 1223003);

	//test #661
	assert(isPrime(6324632) == 0);
	assert(getPrimesCount(3109602, 4917441) == 118972);
	assert(findNextPrime(6324632) == 6324641);

	//test #662
	assert(isPrime(9401942) == 0);
	assert(getPrimesCount(4311125, 5002327) == 45108);
	assert(findNextPrime(9401942) == 9401947);

	//test #663
	assert(isPrime(4300251) == 0);
	assert(getPrimesCount(3539790, 7330434) == 244839);
	assert(findNextPrime(4300251) == 4300253);

	//test #664
	assert(isPrime(1769069) == 1);
	assert(getPrimesCount(1298915, 7272960) == 394009);
	assert(findNextPrime(1769069) == 1769069);

	//test #665
	assert(isPrime(4757510) == 0);
	assert(getPrimesCount(1805123, 8094939) == 410288);
	assert(findNextPrime(4757510) == 4757521);

	//test #666
	assert(isPrime(1851521) == 0);
	assert(getPrimesCount(4147367, 4638920) == 32156);
	assert(findNextPrime(1851521) == 1851539);

	//test #667
	assert(isPrime(5037733) == 1);
	assert(getPrimesCount(6278506, 8667740) == 151046);
	assert(findNextPrime(5037733) == 5037733);

	//test #668
	assert(isPrime(3006153) == 0);
	assert(getPrimesCount(7039364, 7635360) == 37653);
	assert(findNextPrime(3006153) == 3006193);

	//test #669
	assert(isPrime(3061188) == 0);
	assert(getPrimesCount(654920, 4716290) == 276827);
	assert(findNextPrime(3061188) == 3061229);

	//test #670
	assert(isPrime(6803191) == 0);
	assert(getPrimesCount(3005365, 6706471) == 240736);
	assert(findNextPrime(6803191) == 6803201);

	//test #671
	assert(isPrime(5158122) == 0);
	assert(getPrimesCount(3353591, 7272846) == 253485);
	assert(findNextPrime(5158122) == 5158189);

	//test #672
	assert(isPrime(456664) == 0);
	assert(getPrimesCount(3511070, 5806507) == 149552);
	assert(findNextPrime(456664) == 456679);

	//test #673
	assert(isPrime(8214451) == 0);
	assert(getPrimesCount(673406, 7623252) == 461457);
	assert(findNextPrime(8214451) == 8214457);

	//test #674
	assert(isPrime(4445616) == 0);
	assert(getPrimesCount(1698983, 8494944) == 442748);
	assert(findNextPrime(4445616) == 4445621);

	//test #675
	assert(isPrime(1367502) == 0);
	assert(getPrimesCount(3412, 1507066) == 114205);
	assert(findNextPrime(1367502) == 1367507);

	//test #676
	assert(isPrime(7996404) == 0);
	assert(getPrimesCount(472836, 1431729) == 69878);
	assert(findNextPrime(7996404) == 7996423);

	//test #677
	assert(isPrime(83778) == 0);
	assert(getPrimesCount(149741, 9492924) == 619315);
	assert(findNextPrime(83778) == 83791);

	//test #678
	assert(isPrime(5077567) == 0);
	assert(getPrimesCount(1211012, 1847926) == 44710);
	assert(findNextPrime(5077567) == 5077607);

	//test #679
	assert(isPrime(9433200) == 0);
	assert(getPrimesCount(1206095, 5191648) == 267517);
	assert(findNextPrime(9433200) == 9433201);

	//test #680
	assert(isPrime(369571) == 0);
	assert(getPrimesCount(2359533, 8485592) == 396691);
	assert(findNextPrime(369571) == 369581);

	//test #681
	assert(isPrime(4670623) == 0);
	assert(getPrimesCount(1681575, 3966042) == 154079);
	assert(findNextPrime(4670623) == 4670639);

	//test #682
	assert(isPrime(396752) == 0);
	assert(getPrimesCount(2208195, 9998530) == 501260);
	assert(findNextPrime(396752) == 396833);

	//test #683
	assert(isPrime(7602928) == 0);
	assert(getPrimesCount(1517432, 2350709) == 57520);
	assert(findNextPrime(7602928) == 7602929);

	//test #684
	assert(isPrime(1600965) == 0);
	assert(getPrimesCount(1489127, 9705641) == 533004);
	assert(findNextPrime(1600965) == 1600967);

	//test #685
	assert(isPrime(8068345) == 0);
	assert(getPrimesCount(197508, 9304596) == 603689);
	assert(findNextPrime(8068345) == 8068367);

	//test #686
	assert(isPrime(3239809) == 0);
	assert(getPrimesCount(2732903, 5992294) == 213512);
	assert(findNextPrime(3239809) == 3239839);

	//test #687
	assert(isPrime(9893998) == 0);
	assert(getPrimesCount(7983445, 9348732) == 85476);
	assert(findNextPrime(9893998) == 9894007);

	//test #688
	assert(isPrime(7971683) == 1);
	assert(getPrimesCount(3206984, 8249438) == 324758);
	assert(findNextPrime(7971683) == 7971683);

	//test #689
	assert(isPrime(4963080) == 0);
	assert(getPrimesCount(3278397, 3983410) == 46596);
	assert(findNextPrime(4963080) == 4963093);

	//test #690
	assert(isPrime(5212973) == 0);
	assert(getPrimesCount(6682360, 7716968) == 65591);
	assert(findNextPrime(5212973) == 5212979);

	//test #691
	assert(isPrime(8913242) == 0);
	assert(getPrimesCount(1179659, 2293584) == 77605);
	assert(findNextPrime(8913242) == 8913283);

	//test #692
	assert(isPrime(2054549) == 0);
	assert(getPrimesCount(34467, 3921093) == 274310);
	assert(findNextPrime(2054549) == 2054579);

	//test #693
	assert(isPrime(5661309) == 0);
	assert(getPrimesCount(2676793, 3530963) == 57091);
	assert(findNextPrime(5661309) == 5661311);

	//test #694
	assert(isPrime(7832377) == 0);
	assert(getPrimesCount(6455427, 9260914) == 176821);
	assert(findNextPrime(7832377) == 7832381);

	//test #695
	assert(isPrime(1761073) == 0);
	assert(getPrimesCount(1655763, 6777115) == 337384);
	assert(findNextPrime(1761073) == 1761077);

	//test #696
	assert(isPrime(3779809) == 0);
	assert(getPrimesCount(73614, 4925404) == 336367);
	assert(findNextPrime(3779809) == 3779813);

	//test #697
	assert(isPrime(8440651) == 0);
	assert(getPrimesCount(3215363, 3978759) == 50535);
	assert(findNextPrime(8440651) == 8440667);

	//test #698
	assert(isPrime(8190196) == 0);
	assert(getPrimesCount(8571476, 9941373) == 85367);
	assert(findNextPrime(8190196) == 8190211);

	//test #699
	assert(isPrime(6223812) == 0);
	assert(getPrimesCount(4188452, 4537355) == 22787);
	assert(findNextPrime(6223812) == 6223813);

	//test #700
	assert(isPrime(1124981) == 0);
	assert(getPrimesCount(8514496, 9180419) == 41643);
	assert(findNextPrime(1124981) == 1124983);

	//test #701
	assert(isPrime(3706552) == 0);
	assert(getPrimesCount(1535864, 8299600) == 441900);
	assert(findNextPrime(3706552) == 3706609);

	//test #702
	assert(isPrime(7612732) == 0);
	assert(getPrimesCount(1881430, 8289831) == 417218);
	assert(findNextPrime(7612732) == 7612751);

	//test #703
	assert(isPrime(2915351) == 1);
	assert(getPrimesCount(108506, 2967591) == 204316);
	assert(findNextPrime(2915351) == 2915351);

	//test #704
	assert(isPrime(9763805) == 0);
	assert(getPrimesCount(5490523, 9736211) == 268143);
	assert(findNextPrime(9763805) == 9763813);

	//test #705
	assert(isPrime(4718065) == 0);
	assert(getPrimesCount(569441, 7284500) == 447907);
	assert(findNextPrime(4718065) == 4718071);

	//test #706
	assert(isPrime(9565249) == 1);
	assert(getPrimesCount(1074480, 2170121) == 76772);
	assert(findNextPrime(9565249) == 9565249);

	//test #707
	assert(isPrime(9837013) == 0);
	assert(getPrimesCount(1668940, 7943570) == 410274);
	assert(findNextPrime(9837013) == 9837019);

	//test #708
	assert(isPrime(7281049) == 0);
	assert(getPrimesCount(881905, 7298022) == 425585);
	assert(findNextPrime(7281049) == 7281077);

	//test #709
	assert(isPrime(2355369) == 0);
	assert(getPrimesCount(2235490, 3434085) == 80733);
	assert(findNextPrime(2355369) == 2355377);

	//test #710
	assert(isPrime(4558052) == 0);
	assert(getPrimesCount(2330208, 7545078) == 339548);
	assert(findNextPrime(4558052) == 4558069);

	//test #711
	assert(isPrime(6031916) == 0);
	assert(getPrimesCount(536810, 4539591) == 274146);
	assert(findNextPrime(6031916) == 6031931);

	//test #712
	assert(isPrime(4580731) == 1);
	assert(getPrimesCount(4520526, 7822259) == 211296);
	assert(findNextPrime(4580731) == 4580731);

	//test #713
	assert(isPrime(747910) == 0);
	assert(getPrimesCount(4169555, 8098276) == 251599);
	assert(findNextPrime(747910) == 747917);

	//test #714
	assert(isPrime(8107620) == 0);
	assert(getPrimesCount(1335476, 7034037) == 376295);
	assert(findNextPrime(8107620) == 8107621);

	//test #715
	assert(isPrime(5995843) == 0);
	assert(getPrimesCount(321966, 5357357) == 343840);
	assert(findNextPrime(5995843) == 5995853);

	//test #716
	assert(isPrime(3999125) == 0);
	assert(getPrimesCount(5028838, 5284328) == 16509);
	assert(findNextPrime(3999125) == 3999143);

	//test #717
	assert(isPrime(7347930) == 0);
	assert(getPrimesCount(2971079, 4099040) == 74850);
	assert(findNextPrime(7347930) == 7347943);

	//test #718
	assert(isPrime(2569665) == 0);
	assert(getPrimesCount(1548624, 3052545) == 102732);
	assert(findNextPrime(2569665) == 2569667);

	//test #719
	assert(isPrime(7467753) == 0);
	assert(getPrimesCount(4192498, 5757779) == 101488);
	assert(findNextPrime(7467753) == 7467763);

	//test #720
	assert(isPrime(8716433) == 0);
	assert(getPrimesCount(2130849, 3242961) == 75178);
	assert(findNextPrime(8716433) == 8716439);

	//test #721
	assert(isPrime(5138095) == 0);
	assert(getPrimesCount(1148911, 6203890) == 336684);
	assert(findNextPrime(5138095) == 5138099);

	//test #722
	assert(isPrime(2375306) == 0);
	assert(getPrimesCount(1718894, 9910859) == 529653);
	assert(findNextPrime(2375306) == 2375309);

	//test #723
	assert(isPrime(3363957) == 0);
	assert(getPrimesCount(89232, 5234682) == 355025);
	assert(findNextPrime(3363957) == 3363959);

	//test #724
	assert(isPrime(3528888) == 0);
	assert(getPrimesCount(3971836, 4337119) == 23932);
	assert(findNextPrime(3528888) == 3528907);

	//test #725
	assert(isPrime(4508389) == 0);
	assert(getPrimesCount(4181602, 5399070) == 79205);
	assert(findNextPrime(4508389) == 4508431);

	//test #726
	assert(isPrime(5595511) == 0);
	assert(getPrimesCount(896907, 8575951) == 504870);
	assert(findNextPrime(5595511) == 5595539);

	//test #727
	assert(isPrime(5138706) == 0);
	assert(getPrimesCount(7694350, 9509730) == 113652);
	assert(findNextPrime(5138706) == 5138717);

	//test #728
	assert(isPrime(888116) == 0);
	assert(getPrimesCount(2112987, 3550565) == 96740);
	assert(findNextPrime(888116) == 888133);

	//test #729
	assert(isPrime(2115023) == 0);
	assert(getPrimesCount(7751759, 9399772) == 103254);
	assert(findNextPrime(2115023) == 2115049);

	//test #730
	assert(isPrime(9562355) == 0);
	assert(getPrimesCount(815999, 5937443) == 343750);
	assert(findNextPrime(9562355) == 9562363);

	//test #731
	assert(isPrime(7362366) == 0);
	assert(getPrimesCount(6986598, 9926383) == 184266);
	assert(findNextPrime(7362366) == 7362373);

	//test #732
	assert(isPrime(6653549) == 0);
	assert(getPrimesCount(7710689, 8825193) == 69999);
	assert(findNextPrime(6653549) == 6653573);

	//test #733
	assert(isPrime(596567) == 0);
	assert(getPrimesCount(1142528, 4159714) == 204878);
	assert(findNextPrime(596567) == 596569);

	//test #734
	assert(isPrime(2799951) == 0);
	assert(getPrimesCount(814323, 4522398) == 252395);
	assert(findNextPrime(2799951) == 2799959);

	//test #735
	assert(isPrime(2902114) == 0);
	assert(getPrimesCount(4590115, 6089193) == 96754);
	assert(findNextPrime(2902114) == 2902147);

	//test #736
	assert(isPrime(4737533) == 1);
	assert(getPrimesCount(5045300, 7064625) == 129335);
	assert(findNextPrime(4737533) == 4737533);

	//test #737
	assert(isPrime(3673238) == 0);
	assert(getPrimesCount(3270014, 6358747) == 200912);
	assert(findNextPrime(3673238) == 3673253);

	//test #738
	assert(isPrime(2322232) == 0);
	assert(getPrimesCount(4896585, 7273791) == 152234);
	assert(findNextPrime(2322232) == 2322239);

	//test #739
	assert(isPrime(9669219) == 0);
	assert(getPrimesCount(4698493, 9688668) == 316492);
	assert(findNextPrime(9669219) == 9669221);

	//test #740
	assert(isPrime(1212598) == 0);
	assert(getPrimesCount(1909680, 9806480) == 509984);
	assert(findNextPrime(1212598) == 1212611);

	//test #741
	assert(isPrime(6435951) == 0);
	assert(getPrimesCount(3475066, 8112800) == 298284);
	assert(findNextPrime(6435951) == 6435973);

	//test #742
	assert(isPrime(4618592) == 0);
	assert(getPrimesCount(581207, 4395248) == 261351);
	assert(findNextPrime(4618592) == 4618619);

	//test #743
	assert(isPrime(4444140) == 0);
	assert(getPrimesCount(2441054, 5814006) == 221828);
	assert(findNextPrime(4444140) == 4444147);

	//test #744
	assert(isPrime(221847) == 0);
	assert(getPrimesCount(4007554, 5968260) == 127195);
	assert(findNextPrime(221847) == 221849);

	//test #745
	assert(isPrime(8634820) == 0);
	assert(getPrimesCount(5098551, 7809164) == 172857);
	assert(findNextPrime(8634820) == 8634823);

	//test #746
	assert(isPrime(1478961) == 0);
	assert(getPrimesCount(425035, 6494026) == 408589);
	assert(findNextPrime(1478961) == 1478963);

	//test #747
	assert(isPrime(8683784) == 0);
	assert(getPrimesCount(428230, 5137168) == 321350);
	assert(findNextPrime(8683784) == 8683793);

	//test #748
	assert(isPrime(5229886) == 0);
	assert(getPrimesCount(1569490, 9274435) == 500554);
	assert(findNextPrime(5229886) == 5229899);

	//test #749
	assert(isPrime(1644641) == 1);
	assert(getPrimesCount(2550113, 3322141) == 51905);
	assert(findNextPrime(1644641) == 1644641);

	//test #750
	assert(isPrime(8639664) == 0);
	assert(getPrimesCount(5131932, 6897067) == 113086);
	assert(findNextPrime(8639664) == 8639711);

	//test #751
	assert(isPrime(5735016) == 0);
	assert(getPrimesCount(4889917, 6618238) == 111046);
	assert(findNextPrime(5735016) == 5735029);

	//test #752
	assert(isPrime(5415900) == 0);
	assert(getPrimesCount(5304298, 9932300) == 292233);
	assert(findNextPrime(5415900) == 5415901);

	//test #753
	assert(isPrime(4572792) == 0);
	assert(getPrimesCount(4919383, 6555253) == 105045);
	assert(findNextPrime(4572792) == 4572803);

	//test #754
	assert(isPrime(9609069) == 0);
	assert(getPrimesCount(770645, 7033339) == 416989);
	assert(findNextPrime(9609069) == 9609071);

	//test #755
	assert(isPrime(8815694) == 0);
	assert(getPrimesCount(2807890, 4440350) == 108127);
	assert(findNextPrime(8815694) == 8815759);

	//test #756
	assert(isPrime(9221008) == 0);
	assert(getPrimesCount(1679414, 7213567) == 363470);
	assert(findNextPrime(9221008) == 9221011);

	//test #757
	assert(isPrime(3451825) == 0);
	assert(getPrimesCount(1099252, 9686666) == 559594);
	assert(findNextPrime(3451825) == 3451829);

	//test #758
	assert(isPrime(734353) == 0);
	assert(getPrimesCount(301838, 1055397) == 56354);
	assert(findNextPrime(734353) == 734381);

	//test #759
	assert(isPrime(4509753) == 0);
	assert(getPrimesCount(726945, 7660704) == 459858);
	assert(findNextPrime(4509753) == 4509763);

	//test #760
	assert(isPrime(790470) == 0);
	assert(getPrimesCount(1396500, 1958682) == 39246);
	assert(findNextPrime(790470) == 790481);

	//test #761
	assert(isPrime(3835117) == 0);
	assert(getPrimesCount(1756920, 9620196) == 509006);
	assert(findNextPrime(3835117) == 3835123);

	//test #762
	assert(isPrime(4485753) == 0);
	assert(getPrimesCount(6073771, 8554953) == 157046);
	assert(findNextPrime(4485753) == 4485763);

	//test #763
	assert(isPrime(9857594) == 0);
	assert(getPrimesCount(5647661, 5703039) == 3569);
	assert(findNextPrime(9857594) == 9857609);

	//test #764
	assert(isPrime(1096026) == 0);
	assert(getPrimesCount(1013845, 1842040) == 58447);
	assert(findNextPrime(1096026) == 1096031);

	//test #765
	assert(isPrime(6881721) == 0);
	assert(getPrimesCount(4379768, 7827770) == 220881);
	assert(findNextPrime(6881721) == 6881731);

	//test #766
	assert(isPrime(4560083) == 0);
	assert(getPrimesCount(2340300, 8441730) == 395238);
	assert(findNextPrime(4560083) == 4560109);

	//test #767
	assert(isPrime(7611066) == 0);
	assert(getPrimesCount(12533, 6175100) == 422567);
	assert(findNextPrime(7611066) == 7611101);

	//test #768
	assert(isPrime(5128950) == 0);
	assert(getPrimesCount(2787201, 7962997) == 334949);
	assert(findNextPrime(5128950) == 5128967);

	//test #769
	assert(isPrime(6271109) == 0);
	assert(getPrimesCount(7645564, 8366200) == 45312);
	assert(findNextPrime(6271109) == 6271123);

	//test #770
	assert(isPrime(4292873) == 0);
	assert(getPrimesCount(962546, 7853938) == 454774);
	assert(findNextPrime(4292873) == 4292887);

	//test #771
	assert(isPrime(1558625) == 0);
	assert(getPrimesCount(6300070, 9218428) == 183988);
	assert(findNextPrime(1558625) == 1558631);

	//test #772
	assert(isPrime(5233175) == 0);
	assert(getPrimesCount(2417768, 9484303) == 455099);
	assert(findNextPrime(5233175) == 5233177);

	//test #773
	assert(isPrime(1158415) == 0);
	assert(getPrimesCount(4252925, 5702575) == 93992);
	assert(findNextPrime(1158415) == 1158419);

	//test #774
	assert(isPrime(8956198) == 0);
	assert(getPrimesCount(1457152, 2906723) == 99420);
	assert(findNextPrime(8956198) == 8956217);

	//test #775
	assert(isPrime(7600309) == 0);
	assert(getPrimesCount(2237051, 8096470) == 380608);
	assert(findNextPrime(7600309) == 7600319);

	//test #776
	assert(isPrime(1887850) == 0);
	assert(getPrimesCount(7972580, 8922474) == 59577);
	assert(findNextPrime(1887850) == 1887857);

	//test #777
	assert(isPrime(6033499) == 0);
	assert(getPrimesCount(2888848, 7727035) == 313240);
	assert(findNextPrime(6033499) == 6033527);

	//test #778
	assert(isPrime(1042270) == 0);
	assert(getPrimesCount(3119299, 3461964) == 22880);
	assert(findNextPrime(1042270) == 1042271);

	//test #779
	assert(isPrime(3682199) == 1);
	assert(getPrimesCount(6857767, 7828087) == 61348);
	assert(findNextPrime(3682199) == 3682199);

	//test #780
	assert(isPrime(9635247) == 0);
	assert(getPrimesCount(2240907, 6620179) == 287007);
	assert(findNextPrime(9635247) == 9635257);

	//test #781
	assert(isPrime(6613896) == 0);
	assert(getPrimesCount(1750840, 4157406) == 161832);
	assert(findNextPrime(6613896) == 6613913);

	//test #782
	assert(isPrime(4307368) == 0);
	assert(getPrimesCount(170078, 8911216) == 581406);
	assert(findNextPrime(4307368) == 4307377);

	//test #783
	assert(isPrime(376288) == 0);
	assert(getPrimesCount(1410677, 5310261) == 260717);
	assert(findNextPrime(376288) == 376291);

	//test #784
	assert(isPrime(5579084) == 0);
	assert(getPrimesCount(885550, 7439065) == 434202);
	assert(findNextPrime(5579084) == 5579089);

	//test #785
	assert(isPrime(28371) == 0);
	assert(getPrimesCount(8777081, 9376766) == 37392);
	assert(findNextPrime(28371) == 28387);

	//test #786
	assert(isPrime(8161229) == 0);
	assert(getPrimesCount(682468, 2920013) == 156201);
	assert(findNextPrime(8161229) == 8161243);

	//test #787
	assert(isPrime(5435329) == 0);
	assert(getPrimesCount(8925667, 9600184) == 42023);
	assert(findNextPrime(5435329) == 5435333);

	//test #788
	assert(isPrime(1852704) == 0);
	assert(getPrimesCount(3195042, 3678541) == 32098);
	assert(findNextPrime(1852704) == 1852727);

	//test #789
	assert(isPrime(9240275) == 0);
	assert(getPrimesCount(8158102, 8512757) == 22249);
	assert(findNextPrime(9240275) == 9240281);

	//test #790
	assert(isPrime(6326640) == 0);
	assert(getPrimesCount(5285180, 5435708) == 9719);
	assert(findNextPrime(6326640) == 6326641);

	//test #791
	assert(isPrime(3950590) == 0);
	assert(getPrimesCount(1676834, 5713642) == 267962);
	assert(findNextPrime(3950590) == 3950599);

	//test #792
	assert(isPrime(6507375) == 0);
	assert(getPrimesCount(5779488, 7949502) == 137938);
	assert(findNextPrime(6507375) == 6507407);

	//test #793
	assert(isPrime(5575007) == 1);
	assert(getPrimesCount(1996628, 3954126) == 131488);
	assert(findNextPrime(5575007) == 5575007);

	//test #794
	assert(isPrime(9142651) == 0);
	assert(getPrimesCount(6019373, 6846273) == 52728);
	assert(findNextPrime(9142651) == 9142691);

	//test #795
	assert(isPrime(3484317) == 0);
	assert(getPrimesCount(6935436, 7002634) == 4273);
	assert(findNextPrime(3484317) == 3484319);

	//test #796
	assert(isPrime(6097547) == 1);
	assert(getPrimesCount(9490481, 9995997) == 31347);
	assert(findNextPrime(6097547) == 6097547);

	//test #797
	assert(isPrime(9929583) == 0);
	assert(getPrimesCount(1694989, 3901388) == 148914);
	assert(findNextPrime(9929583) == 9929587);

	//test #798
	assert(isPrime(3178659) == 0);
	assert(getPrimesCount(1184213, 8225792) == 462134);
	assert(findNextPrime(3178659) == 3178667);

	//test #799
	assert(isPrime(2468672) == 0);
	assert(getPrimesCount(3259339, 8536311) == 339237);
	assert(findNextPrime(2468672) == 2468693);

	//test #800
	assert(isPrime(1556797) == 0);
	assert(getPrimesCount(1323697, 3827325) == 170091);
	assert(findNextPrime(1556797) == 1556837);

	//test #801
	assert(isPrime(8369335) == 0);
	assert(getPrimesCount(8676029, 9758484) == 67490);
	assert(findNextPrime(8369335) == 8369341);

	//test #802
	assert(isPrime(388614) == 0);
	assert(getPrimesCount(3403480, 3544695) == 9272);
	assert(findNextPrime(388614) == 388621);

	//test #803
	assert(isPrime(1713945) == 0);
	assert(getPrimesCount(727485, 4721548) == 271770);
	assert(findNextPrime(1713945) == 1713977);

	//test #804
	assert(isPrime(3186055) == 0);
	assert(getPrimesCount(443081, 3328738) == 201632);
	assert(findNextPrime(3186055) == 3186061);

	//test #805
	assert(isPrime(3079283) == 1);
	assert(getPrimesCount(1643133, 6035043) == 290952);
	assert(findNextPrime(3079283) == 3079283);

	//test #806
	assert(isPrime(881208) == 0);
	assert(getPrimesCount(3325304, 8416186) == 327308);
	assert(findNextPrime(881208) == 881219);

	//test #807
	assert(isPrime(4426372) == 0);
	assert(getPrimesCount(2573257, 7437463) == 316291);
	assert(findNextPrime(4426372) == 4426379);

	//test #808
	assert(isPrime(716824) == 0);
	assert(getPrimesCount(802424, 2212242) == 99390);
	assert(findNextPrime(716824) == 716827);

	//test #809
	assert(isPrime(600207) == 0);
	assert(getPrimesCount(3393566, 6594083) == 207673);
	assert(findNextPrime(600207) == 600217);

	//test #810
	assert(isPrime(90098) == 0);
	assert(getPrimesCount(3852687, 6738783) == 186504);
	assert(findNextPrime(90098) == 90107);

	//test #811
	assert(isPrime(662874) == 0);
	assert(getPrimesCount(7007604, 8672490) == 104869);
	assert(findNextPrime(662874) == 662897);

	//test #812
	assert(isPrime(174466) == 0);
	assert(getPrimesCount(1864752, 2053887) == 13069);
	assert(findNextPrime(174466) == 174467);

	//test #813
	assert(isPrime(5740089) == 0);
	assert(getPrimesCount(1773574, 4246814) == 166158);
	assert(findNextPrime(5740089) == 5740093);

	//test #814
	assert(isPrime(6062145) == 0);
	assert(getPrimesCount(800756, 5836982) == 338338);
	assert(findNextPrime(6062145) == 6062153);

	//test #815
	assert(isPrime(7249141) == 1);
	assert(getPrimesCount(5209439, 7477059) == 144798);
	assert(findNextPrime(7249141) == 7249141);

	//test #816
	assert(isPrime(7183550) == 0);
	assert(getPrimesCount(83967, 2555942) == 178680);
	assert(findNextPrime(7183550) == 7183559);

	//test #817
	assert(isPrime(5977323) == 0);
	assert(getPrimesCount(161132, 2519038) == 169576);
	assert(findNextPrime(5977323) == 5977331);

	//test #818
	assert(isPrime(2509797) == 0);
	assert(getPrimesCount(1326962, 2585934) == 86980);
	assert(findNextPrime(2509797) == 2509807);

	//test #819
	assert(isPrime(6409216) == 0);
	assert(getPrimesCount(3204645, 3539333) == 22179);
	assert(findNextPrime(6409216) == 6409217);

	//test #820
	assert(isPrime(9578960) == 0);
	assert(getPrimesCount(589163, 7851019) == 482106);
	assert(findNextPrime(9578960) == 9578963);

	//test #821
	assert(isPrime(5591418) == 0);
	assert(getPrimesCount(5888148, 9769746) == 244710);
	assert(findNextPrime(5591418) == 5591431);

	//test #822
	assert(isPrime(8807783) == 1);
	assert(getPrimesCount(5762324, 9086893) == 210237);
	assert(findNextPrime(8807783) == 8807783);

	//test #823
	assert(isPrime(6621069) == 0);
	assert(getPrimesCount(63554, 1462369) == 105142);
	assert(findNextPrime(6621069) == 6621071);

	//test #824
	assert(isPrime(9256837) == 1);
	assert(getPrimesCount(4045151, 8871986) == 308289);
	assert(findNextPrime(9256837) == 9256837);

	//test #825
	assert(isPrime(244762) == 0);
	assert(getPrimesCount(2619480, 7599424) == 323348);
	assert(findNextPrime(244762) == 244781);

	//test #826
	assert(isPrime(4419452) == 0);
	assert(getPrimesCount(8673598, 8701622) == 1747);
	assert(findNextPrime(4419452) == 4419461);

	//test #827
	assert(isPrime(3005632) == 0);
	assert(getPrimesCount(3606260, 7021524) == 220861);
	assert(findNextPrime(3005632) == 3005633);

	//test #828
	assert(isPrime(6154005) == 0);
	assert(getPrimesCount(689095, 4315023) == 248063);
	assert(findNextPrime(6154005) == 6154007);

	//test #829
	assert(isPrime(5650828) == 0);
	assert(getPrimesCount(3763756, 5881564) == 137614);
	assert(findNextPrime(5650828) == 5650829);

	//test #830
	assert(isPrime(805566) == 0);
	assert(getPrimesCount(719723, 2782348) == 144165);
	assert(findNextPrime(805566) == 805573);

	//test #831
	assert(isPrime(5289965) == 0);
	assert(getPrimesCount(1657515, 9522968) == 509849);
	assert(findNextPrime(5289965) == 5289967);

	//test #832
	assert(isPrime(4771681) == 0);
	assert(getPrimesCount(7151948, 9331191) == 136809);
	assert(findNextPrime(4771681) == 4771687);

	//test #833
	assert(isPrime(9965889) == 0);
	assert(getPrimesCount(4261334, 4979324) == 46830);
	assert(findNextPrime(9965889) == 9965903);

	//test #834
	assert(isPrime(2462033) == 0);
	assert(getPrimesCount(2392572, 9437389) == 453902);
	assert(findNextPrime(2462033) == 2462041);

	//test #835
	assert(isPrime(1721201) == 1);
	assert(getPrimesCount(3588769, 4529007) == 61832);
	assert(findNextPrime(1721201) == 1721201);

	//test #836
	assert(isPrime(7518027) == 0);
	assert(getPrimesCount(2586049, 5753518) == 208114);
	assert(findNextPrime(7518027) == 7518031);

	//test #837
	assert(isPrime(7940917) == 0);
	assert(getPrimesCount(4070304, 4983047) == 59594);
	assert(findNextPrime(7940917) == 7940927);

	//test #838
	assert(isPrime(5839546) == 0);
	assert(getPrimesCount(3566736, 5841369) == 148113);
	assert(findNextPrime(5839546) == 5839553);

	//test #839
	assert(isPrime(8824538) == 0);
	assert(getPrimesCount(1874660, 2715330) == 57417);
	assert(findNextPrime(8824538) == 8824549);

	//test #840
	assert(isPrime(2971134) == 0);
	assert(getPrimesCount(4622197, 4842878) == 14347);
	assert(findNextPrime(2971134) == 2971139);

	//test #841
	assert(isPrime(1064241) == 0);
	assert(getPrimesCount(2599035, 6015952) == 224078);
	assert(findNextPrime(1064241) == 1064243);

	//test #842
	assert(isPrime(6351660) == 0);
	assert(getPrimesCount(4279631, 8474394) == 267983);
	assert(findNextPrime(6351660) == 6351671);

	//test #843
	assert(isPrime(1920473) == 0);
	assert(getPrimesCount(39623, 7685084) == 515784);
	assert(findNextPrime(1920473) == 1920487);

	//test #844
	assert(isPrime(3676596) == 0);
	assert(getPrimesCount(361662, 3809599) == 239733);
	assert(findNextPrime(3676596) == 3676597);

	//test #845
	assert(isPrime(1466927) == 0);
	assert(getPrimesCount(2811101, 3605526) == 52968);
	assert(findNextPrime(1466927) == 1466929);

	//test #846
	assert(isPrime(1021367) == 1);
	assert(getPrimesCount(1812194, 3878523) == 139245);
	assert(findNextPrime(1021367) == 1021367);

	//test #847
	assert(isPrime(1982298) == 0);
	assert(getPrimesCount(7031599, 9138236) == 132376);
	assert(findNextPrime(1982298) == 1982371);

	//test #848
	assert(isPrime(1426931) == 0);
	assert(getPrimesCount(3104404, 8755426) == 363405);
	assert(findNextPrime(1426931) == 1426933);

	//test #849
	assert(isPrime(6274573) == 0);
	assert(getPrimesCount(4787943, 5901027) == 71827);
	assert(findNextPrime(6274573) == 6274577);

	//test #850
	assert(isPrime(1292881) == 0);
	assert(getPrimesCount(1210881, 4175543) == 201022);
	assert(findNextPrime(1292881) == 1292887);

	//test #851
	assert(isPrime(2577862) == 0);
	assert(getPrimesCount(341815, 3646385) == 230512);
	assert(findNextPrime(2577862) == 2577871);

	//test #852
	assert(isPrime(4987306) == 0);
	assert(getPrimesCount(5812793, 8563869) == 174337);
	assert(findNextPrime(4987306) == 4987319);

	//test #853
	assert(isPrime(4991845) == 0);
	assert(getPrimesCount(173050, 3535909) == 236748);
	assert(findNextPrime(4991845) == 4991849);

	//test #854
	assert(isPrime(5417696) == 0);
	assert(getPrimesCount(5888281, 9797591) == 246434);
	assert(findNextPrime(5417696) == 5417701);

	//test #855
	assert(isPrime(4765070) == 0);
	assert(getPrimesCount(1210108, 7673926) == 425632);
	assert(findNextPrime(4765070) == 4765073);

	//test #856
	assert(isPrime(7226358) == 0);
	assert(getPrimesCount(5372394, 6927145) == 99444);
	assert(findNextPrime(7226358) == 7226363);

	//test #857
	assert(isPrime(6458386) == 0);
	assert(getPrimesCount(4388776, 9711963) == 338189);
	assert(findNextPrime(6458386) == 6458393);

	//test #858
	assert(isPrime(8012710) == 0);
	assert(getPrimesCount(8367792, 8615393) == 15570);
	assert(findNextPrime(8012710) == 8012713);

	//test #859
	assert(isPrime(5618441) == 1);
	assert(getPrimesCount(1151057, 1298317) == 10526);
	assert(findNextPrime(5618441) == 5618441);

	//test #860
	assert(isPrime(4702298) == 0);
	assert(getPrimesCount(294178, 3263133) == 208910);
	assert(findNextPrime(4702298) == 4702309);

	//test #861
	assert(isPrime(3836944) == 0);
	assert(getPrimesCount(2370819, 8863330) == 419619);
	assert(findNextPrime(3836944) == 3836957);

	//test #862
	assert(isPrime(773999) == 1);
	assert(getPrimesCount(108500, 480780) == 29748);
	assert(findNextPrime(773999) == 773999);

	//test #863
	assert(isPrime(7241212) == 0);
	assert(getPrimesCount(617472, 8052495) == 492621);
	assert(findNextPrime(7241212) == 7241257);

	//test #864
	assert(isPrime(1708838) == 0);
	assert(getPrimesCount(7462928, 9778340) == 144984);
	assert(findNextPrime(1708838) == 1708853);

	//test #865
	assert(isPrime(8961774) == 0);
	assert(getPrimesCount(8289771, 8571017) == 17637);
	assert(findNextPrime(8961774) == 8961779);

	//test #866
	assert(isPrime(3500808) == 0);
	assert(getPrimesCount(2832141, 5415384) == 169781);
	assert(findNextPrime(3500808) == 3500831);

	//test #867
	assert(isPrime(3094365) == 0);
	assert(getPrimesCount(1692658, 8142792) == 421089);
	assert(findNextPrime(3094365) == 3094411);

	//test #868
	assert(isPrime(9908235) == 0);
	assert(getPrimesCount(6198382, 7261408) == 67668);
	assert(findNextPrime(9908235) == 9908257);

	//test #869
	assert(isPrime(7090694) == 0);
	assert(getPrimesCount(3975989, 7507668) == 227139);
	assert(findNextPrime(7090694) == 7090697);

	//test #870
	assert(isPrime(4157394) == 0);
	assert(getPrimesCount(816373, 8578302) == 510940);
	assert(findNextPrime(4157394) == 4157399);

	//test #871
	assert(isPrime(2391324) == 0);
	assert(getPrimesCount(1141675, 9142686) == 522606);
	assert(findNextPrime(2391324) == 2391331);

	//test #872
	assert(isPrime(5964772) == 0);
	assert(getPrimesCount(7265262, 9462220) == 137772);
	assert(findNextPrime(5964772) == 5964793);

	//test #873
	assert(isPrime(4931806) == 0);
	assert(getPrimesCount(2241821, 9593622) == 473932);
	assert(findNextPrime(4931806) == 4931813);

	//test #874
	assert(isPrime(1885950) == 0);
	assert(getPrimesCount(1578781, 6934804) == 352822);
	assert(findNextPrime(1885950) == 1885979);

	//test #875
	assert(isPrime(2734511) == 0);
	assert(getPrimesCount(723601, 7779389) == 467559);
	assert(findNextPrime(2734511) == 2734513);

	//test #876
	assert(isPrime(7643625) == 0);
	assert(getPrimesCount(1660352, 2500950) == 57773);
	assert(findNextPrime(7643625) == 7643633);

	//test #877
	assert(isPrime(9213748) == 0);
	assert(getPrimesCount(128464, 7695661) == 508607);
	assert(findNextPrime(9213748) == 9213749);

	//test #878
	assert(isPrime(5123097) == 0);
	assert(getPrimesCount(6706572, 9939762) == 202974);
	assert(findNextPrime(5123097) == 5123099);

	//test #879
	assert(isPrime(334607) == 0);
	assert(getPrimesCount(6366015, 7869147) == 95261);
	assert(findNextPrime(334607) == 334619);

	//test #880
	assert(isPrime(4413453) == 0);
	assert(getPrimesCount(2118005, 5382266) == 216161);
	assert(findNextPrime(4413453) == 4413457);

	//test #881
	assert(isPrime(2275779) == 0);
	assert(getPrimesCount(6889336, 7471495) == 36854);
	assert(findNextPrime(2275779) == 2275813);

	//test #882
	assert(isPrime(2832130) == 0);
	assert(getPrimesCount(2835591, 4008778) == 77918);
	assert(findNextPrime(2832130) == 2832131);

	//test #883
	assert(isPrime(2839) == 0);
	assert(getPrimesCount(3318516, 6076484) == 179610);
	assert(findNextPrime(2839) == 2843);

	//test #884
	assert(isPrime(8282738) == 0);
	assert(getPrimesCount(359596, 9875557) == 626202);
	assert(findNextPrime(8282738) == 8282753);

	//test #885
	assert(isPrime(944816) == 0);
	assert(getPrimesCount(126889, 7719656) == 510249);
	assert(findNextPrime(944816) == 944821);

	//test #886
	assert(isPrime(5526236) == 0);
	assert(getPrimesCount(4317054, 7454073) == 201455);
	assert(findNextPrime(5526236) == 5526239);

	//test #887
	assert(isPrime(1427084) == 0);
	assert(getPrimesCount(159370, 1547083) == 102824);
	assert(findNextPrime(1427084) == 1427089);

	//test #888
	assert(isPrime(9650481) == 0);
	assert(getPrimesCount(181346, 1100000) == 69274);
	assert(findNextPrime(9650481) == 9650503);

	//test #889
	assert(isPrime(7653347) == 0);
	assert(getPrimesCount(3556472, 7240803) == 238059);
	assert(findNextPrime(7653347) == 7653353);

	//test #890
	assert(isPrime(6911093) == 0);
	assert(getPrimesCount(4684339, 5554643) == 56335);
	assert(findNextPrime(6911093) == 6911101);

	//test #891
	assert(isPrime(4789381) == 1);
	assert(getPrimesCount(692286, 5867180) == 348316);
	assert(findNextPrime(4789381) == 4789381);

	//test #892
	assert(isPrime(377874) == 0);
	assert(getPrimesCount(3083773, 9163061) == 390181);
	assert(findNextPrime(377874) == 377887);

	//test #893
	assert(isPrime(992672) == 0);
	assert(getPrimesCount(3433589, 9125878) == 364461);
	assert(findNextPrime(992672) == 992689);

	//test #894
	assert(isPrime(3387862) == 0);
	assert(getPrimesCount(1246188, 6416195) == 343251);
	assert(findNextPrime(3387862) == 3387863);

	//test #895
	assert(isPrime(8785719) == 0);
	assert(getPrimesCount(778985, 2502025) == 120808);
	assert(findNextPrime(8785719) == 8785783);

	//test #896
	assert(isPrime(1607390) == 0);
	assert(getPrimesCount(5012104, 8741853) == 237072);
	assert(findNextPrime(1607390) == 1607399);

	//test #897
	assert(isPrime(592311) == 0);
	assert(getPrimesCount(8692962, 9386411) == 43281);
	assert(findNextPrime(592311) == 592321);

	//test #898
	assert(isPrime(2432276) == 0);
	assert(getPrimesCount(201745, 1916893) == 125087);
	assert(findNextPrime(2432276) == 2432279);

	//test #899
	assert(isPrime(8485058) == 0);
	assert(getPrimesCount(1604837, 6214302) == 305053);
	assert(findNextPrime(8485058) == 8485063);

	//test #900
	assert(isPrime(5854963) == 0);
	assert(getPrimesCount(2642047, 2904087) == 17668);
	assert(findNextPrime(5854963) == 5854993);

	//test #901
	assert(isPrime(9900713) == 0);
	assert(getPrimesCount(3413416, 6927935) == 227584);
	assert(findNextPrime(9900713) == 9900733);

	//test #902
	assert(isPrime(7737076) == 0);
	assert(getPrimesCount(6589477, 6999324) == 26108);
	assert(findNextPrime(7737076) == 7737101);

	//test #903
	assert(isPrime(8884802) == 0);
	assert(getPrimesCount(3343857, 5568476) == 145340);
	assert(findNextPrime(8884802) == 8884807);

	//test #904
	assert(isPrime(6099581) == 0);
	assert(getPrimesCount(4013348, 5152054) == 74311);
	assert(findNextPrime(6099581) == 6099601);

	//test #905
	assert(isPrime(2749840) == 0);
	assert(getPrimesCount(4950191, 5660486) == 45801);
	assert(findNextPrime(2749840) == 2749847);

	//test #906
	assert(isPrime(616466) == 0);
	assert(getPrimesCount(2394714, 8758813) == 411474);
	assert(findNextPrime(616466) == 616481);

	//test #907
	assert(isPrime(983677) == 0);
	assert(getPrimesCount(810128, 5108836) == 290838);
	assert(findNextPrime(983677) == 983699);

	//test #908
	assert(isPrime(8818257) == 0);
	assert(getPrimesCount(6101330, 6919302) == 52170);
	assert(findNextPrime(8818257) == 8818259);

	//test #909
	assert(isPrime(7416135) == 0);
	assert(getPrimesCount(7532575, 8814243) == 80581);
	assert(findNextPrime(7416135) == 7416139);

	//test #910
	assert(isPrime(7361162) == 0);
	assert(getPrimesCount(8393707, 9686122) == 80734);
	assert(findNextPrime(7361162) == 7361171);

	//test #911
	assert(isPrime(2985100) == 0);
	assert(getPrimesCount(7146991, 9217713) == 130044);
	assert(findNextPrime(2985100) == 2985107);

	//test #912
	assert(isPrime(5446430) == 0);
	assert(getPrimesCount(988483, 7468875) == 428632);
	assert(findNextPrime(5446430) == 5446451);

	//test #913
	assert(isPrime(1616888) == 0);
	assert(getPrimesCount(2540985, 9752304) == 463457);
	assert(findNextPrime(1616888) == 1616891);

	//test #914
	assert(isPrime(6045873) == 0);
	assert(getPrimesCount(6781619, 9289093) == 157759);
	assert(findNextPrime(6045873) == 6045881);

	//test #915
	assert(isPrime(3237342) == 0);
	assert(getPrimesCount(4260092, 8306589) == 258775);
	assert(findNextPrime(3237342) == 3237347);

	//test #916
	assert(isPrime(9319744) == 0);
	assert(getPrimesCount(5069870, 5111449) == 2686);
	assert(findNextPrime(9319744) == 9319753);

	//test #917
	assert(isPrime(5073148) == 0);
	assert(getPrimesCount(60123, 8045091) == 536528);
	assert(findNextPrime(5073148) == 5073149);

	//test #918
	assert(isPrime(3827671) == 1);
	assert(getPrimesCount(1112781, 2507461) == 96914);
	assert(findNextPrime(3827671) == 3827671);

	//test #919
	assert(isPrime(9872437) == 1);
	assert(getPrimesCount(2994343, 9002552) == 386206);
	assert(findNextPrime(9872437) == 9872437);

	//test #920
	assert(isPrime(9165632) == 0);
	assert(getPrimesCount(3180179, 4091057) == 60330);
	assert(findNextPrime(9165632) == 9165643);

	//test #921
	assert(isPrime(4949197) == 0);
	assert(getPrimesCount(901028, 6646621) == 382777);
	assert(findNextPrime(4949197) == 4949213);

	//test #922
	assert(isPrime(5846081) == 0);
	assert(getPrimesCount(906512, 8402155) == 493279);
	assert(findNextPrime(5846081) == 5846083);

	//test #923
	assert(isPrime(6326354) == 0);
	assert(getPrimesCount(210861, 9191274) == 595483);
	assert(findNextPrime(6326354) == 6326377);

	//test #924
	assert(isPrime(9563086) == 0);
	assert(getPrimesCount(2581378, 7449068) == 316476);
	assert(findNextPrime(9563086) == 9563093);

	//test #925
	assert(isPrime(661534) == 0);
	assert(getPrimesCount(1761165, 2137983) == 26062);
	assert(findNextPrime(661534) == 661541);

	//test #926
	assert(isPrime(2621723) == 0);
	assert(getPrimesCount(88730, 9525121) == 626558);
	assert(findNextPrime(2621723) == 2621737);

	//test #927
	assert(isPrime(3482896) == 0);
	assert(getPrimesCount(3225277, 6100083) == 187328);
	assert(findNextPrime(3482896) == 3482939);

	//test #928
	assert(isPrime(6121240) == 0);
	assert(getPrimesCount(2528159, 7099744) == 298014);
	assert(findNextPrime(6121240) == 6121253);

	//test #929
	assert(isPrime(5767655) == 0);
	assert(getPrimesCount(8104178, 9280598) == 73690);
	assert(findNextPrime(5767655) == 5767669);

	//test #930
	assert(isPrime(631934) == 0);
	assert(getPrimesCount(4363883, 7746893) == 216845);
	assert(findNextPrime(631934) == 631937);

	//test #931
	assert(isPrime(2436472) == 0);
	assert(getPrimesCount(2202431, 5057677) == 189411);
	assert(findNextPrime(2436472) == 2436479);

	//test #932
	assert(isPrime(4779576) == 0);
	assert(getPrimesCount(4409778, 8749452) == 276859);
	assert(findNextPrime(4779576) == 4779589);

	//test #933
	assert(isPrime(2931000) == 0);
	assert(getPrimesCount(5110981, 6457853) == 86411);
	assert(findNextPrime(2931000) == 2931041);

	//test #934
	assert(isPrime(6429117) == 0);
	assert(getPrimesCount(249157, 9308745) == 599745);
	assert(findNextPrime(6429117) == 6429139);

	//test #935
	assert(isPrime(6347880) == 0);
	assert(getPrimesCount(2787410, 8544402) == 371422);
	assert(findNextPrime(6347880) == 6347903);

	//test #936
	assert(isPrime(9875686) == 0);
	assert(getPrimesCount(3080359, 7407872) == 280279);
	assert(findNextPrime(9875686) == 9875693);

	//test #937
	assert(isPrime(2848425) == 0);
	assert(getPrimesCount(963375, 7581774) == 437528);
	assert(findNextPrime(2848425) == 2848453);

	//test #938
	assert(isPrime(446728) == 0);
	assert(getPrimesCount(446135, 1392985) == 69165);
	assert(findNextPrime(446728) == 446731);

	//test #939
	assert(isPrime(4400605) == 0);
	assert(getPrimesCount(7966557, 8232500) == 16690);
	assert(findNextPrime(4400605) == 4400621);

	//test #940
	assert(isPrime(2310404) == 0);
	assert(getPrimesCount(7072722, 7187239) == 7232);
	assert(findNextPrime(2310404) == 2310421);

	//test #941
	assert(isPrime(2340516) == 0);
	assert(getPrimesCount(4774678, 8327736) == 226546);
	assert(findNextPrime(2340516) == 2340521);

	//test #942
	assert(isPrime(3147033) == 0);
	assert(getPrimesCount(2944152, 9012315) == 390154);
	assert(findNextPrime(3147033) == 3147049);

	//test #943
	assert(isPrime(883671) == 0);
	assert(getPrimesCount(3804743, 9850131) == 385056);
	assert(findNextPrime(883671) == 883691);

	//test #944
	assert(isPrime(5478620) == 0);
	assert(getPrimesCount(7170194, 7709592) == 34050);
	assert(findNextPrime(5478620) == 5478637);

	//test #945
	assert(isPrime(9614728) == 0);
	assert(getPrimesCount(7876520, 9940405) == 128926);
	assert(findNextPrime(9614728) == 9614729);

	//test #946
	assert(isPrime(1720413) == 0);
	assert(getPrimesCount(794809, 7555014) == 448166);
	assert(findNextPrime(1720413) == 1720421);

	//test #947
	assert(isPrime(1653185) == 0);
	assert(getPrimesCount(2233326, 5682193) == 227491);
	assert(findNextPrime(1653185) == 1653191);

	//test #948
	assert(isPrime(1122902) == 0);
	assert(getPrimesCount(646374, 1935138) == 91921);
	assert(findNextPrime(1122902) == 1122923);

	//test #949
	assert(isPrime(453672) == 0);
	assert(getPrimesCount(2883478, 4418714) == 101554);
	assert(findNextPrime(453672) == 453683);

	//test #950
	assert(isPrime(8710454) == 0);
	assert(getPrimesCount(185135, 8230739) == 537500);
	assert(findNextPrime(8710454) == 8710459);

	//test #951
	assert(isPrime(4775980) == 0);
	assert(getPrimesCount(9415576, 9455565) == 2460);
	assert(findNextPrime(4775980) == 4775993);

	//test #952
	assert(isPrime(5182287) == 0);
	assert(getPrimesCount(1967380, 2504470) == 36683);
	assert(findNextPrime(5182287) == 5182313);

	//test #953
	assert(isPrime(4852705) == 0);
	assert(getPrimesCount(6022557, 7999130) == 125422);
	assert(findNextPrime(4852705) == 4852711);

	//test #954
	assert(isPrime(2812548) == 0);
	assert(getPrimesCount(2083475, 4708370) == 174825);
	assert(findNextPrime(2812548) == 2812549);

	//test #955
	assert(isPrime(79247) == 0);
	assert(getPrimesCount(2633999, 8174648) == 358532);
	assert(findNextPrime(79247) == 79259);

	//test #956
	assert(isPrime(6226583) == 0);
	assert(getPrimesCount(1124522, 4996024) == 260776);
	assert(findNextPrime(6226583) == 6226589);

	//test #957
	assert(isPrime(6171360) == 0);
	assert(getPrimesCount(3647837, 8945228) == 339125);
	assert(findNextPrime(6171360) == 6171377);

	//test #958
	assert(isPrime(7177760) == 0);
	assert(getPrimesCount(2955049, 8607799) == 364143);
	assert(findNextPrime(7177760) == 7177783);

	//test #959
	assert(isPrime(9756851) == 0);
	assert(getPrimesCount(6369560, 9635868) == 205564);
	assert(findNextPrime(9756851) == 9756869);

	//test #960
	assert(isPrime(4233666) == 0);
	assert(getPrimesCount(6165709, 7257888) == 69528);
	assert(findNextPrime(4233666) == 4233667);

	//test #961
	assert(isPrime(3770783) == 0);
	assert(getPrimesCount(571876, 736965) == 12329);
	assert(findNextPrime(3770783) == 3770807);

	//test #962
	assert(isPrime(3248924) == 0);
	assert(getPrimesCount(2731392, 4975464) == 148142);
	assert(findNextPrime(3248924) == 3248939);

	//test #963
	assert(isPrime(5898009) == 0);
	assert(getPrimesCount(1870278, 5704999) == 253961);
	assert(findNextPrime(5898009) == 5898023);

	//test #964
	assert(isPrime(9904078) == 0);
	assert(getPrimesCount(5008927, 7661570) == 169389);
	assert(findNextPrime(9904078) == 9904079);

	//test #965
	assert(isPrime(9353316) == 0);
	assert(getPrimesCount(225915, 1679684) == 106639);
	assert(findNextPrime(9353316) == 9353411);

	//test #966
	assert(isPrime(4053049) == 0);
	assert(getPrimesCount(3546653, 9190981) == 361151);
	assert(findNextPrime(4053049) == 4053059);

	//test #967
	assert(isPrime(7760475) == 0);
	assert(getPrimesCount(6271914, 7238182) == 61491);
	assert(findNextPrime(7760475) == 7760479);

	//test #968
	assert(isPrime(4243536) == 0);
	assert(getPrimesCount(2379464, 9514612) == 459624);
	assert(findNextPrime(4243536) == 4243543);

	//test #969
	assert(isPrime(6434673) == 0);
	assert(getPrimesCount(3425736, 5301762) == 122752);
	assert(findNextPrime(6434673) == 6434683);

	//test #970
	assert(isPrime(8631692) == 0);
	assert(getPrimesCount(2787284, 8082976) == 342462);
	assert(findNextPrime(8631692) == 8631713);

	//test #971
	assert(isPrime(6947495) == 0);
	assert(getPrimesCount(2242598, 9728173) == 482228);
	assert(findNextPrime(6947495) == 6947513);

	//test #972
	assert(isPrime(2490067) == 0);
	assert(getPrimesCount(1040486, 7733779) == 441583);
	assert(findNextPrime(2490067) == 2490079);

	//test #973
	assert(isPrime(7787036) == 0);
	assert(getPrimesCount(2079430, 8282482) == 403100);
	assert(findNextPrime(7787036) == 7787047);

	//test #974
	assert(isPrime(628552) == 0);
	assert(getPrimesCount(5092734, 5123474) == 1984);
	assert(findNextPrime(628552) == 628561);

	//test #975
	assert(isPrime(4315859) == 0);
	assert(getPrimesCount(1862178, 4635227) == 185338);
	assert(findNextPrime(4315859) == 4315873);

	//test #976
	assert(isPrime(9792926) == 0);
	assert(getPrimesCount(6905832, 7390772) == 30747);
	assert(findNextPrime(9792926) == 9792943);

	//test #977
	assert(isPrime(5855695) == 0);
	assert(getPrimesCount(753034, 7918119) == 474169);
	assert(findNextPrime(5855695) == 5855699);

	//test #978
	assert(isPrime(4484581) == 0);
	assert(getPrimesCount(115492, 8743534) == 575547);
	assert(findNextPrime(4484581) == 4484591);

	//test #979
	assert(isPrime(528306) == 0);
	assert(getPrimesCount(830022, 3039632) == 153281);
	assert(findNextPrime(528306) == 528313);

	//test #980
	assert(isPrime(2605539) == 0);
	assert(getPrimesCount(3586046, 9698993) == 390194);
	assert(findNextPrime(2605539) == 2605543);

	//test #981
	assert(isPrime(1746410) == 0);
	assert(getPrimesCount(2354070, 6233997) == 254648);
	assert(findNextPrime(1746410) == 1746419);

	//test #982
	assert(isPrime(8730564) == 0);
	assert(getPrimesCount(3883968, 9051528) == 330103);
	assert(findNextPrime(8730564) == 8730577);

	//test #983
	assert(isPrime(5256717) == 0);
	assert(getPrimesCount(9106631, 9132081) == 1547);
	assert(findNextPrime(5256717) == 5256737);

	//test #984
	assert(isPrime(2886848) == 0);
	assert(getPrimesCount(1726966, 9611835) == 510559);
	assert(findNextPrime(2886848) == 2886859);

	//test #985
	assert(isPrime(8539880) == 0);
	assert(getPrimesCount(927091, 7285005) == 421439);
	assert(findNextPrime(8539880) == 8539889);

	//test #986
	assert(isPrime(5907108) == 0);
	assert(getPrimesCount(4862998, 4892661) == 1963);
	assert(findNextPrime(5907108) == 5907127);

	//test #987
	assert(isPrime(6925663) == 1);
	assert(getPrimesCount(3102894, 3306283) == 13633);
	assert(findNextPrime(6925663) == 6925663);

	//test #988
	assert(isPrime(5849439) == 0);
	assert(getPrimesCount(3329421, 7677709) == 280621);
	assert(findNextPrime(5849439) == 5849453);

	//test #989
	assert(isPrime(2712842) == 0);
	assert(getPrimesCount(3617673, 7717451) == 264062);
	assert(findNextPrime(2712842) == 2712851);

	//test #990
	assert(isPrime(4467748) == 0);
	assert(getPrimesCount(2247636, 3957576) == 114492);
	assert(findNextPrime(4467748) == 4467767);

	//test #991
	assert(isPrime(1331879) == 0);
	assert(getPrimesCount(23972, 2643076) == 190112);
	assert(findNextPrime(1331879) == 1331921);

	//test #992
	assert(isPrime(1058450) == 0);
	assert(getPrimesCount(102425, 2205356) == 153227);
	assert(findNextPrime(1058450) == 1058461);

	//test #993
	assert(isPrime(6101919) == 0);
	assert(getPrimesCount(1388659, 2774485) == 95358);
	assert(findNextPrime(6101919) == 6101941);

	//test #994
	assert(isPrime(2864106) == 0);
	assert(getPrimesCount(712014, 2463479) == 123141);
	assert(findNextPrime(2864106) == 2864129);

	//test #995
	assert(isPrime(6803514) == 0);
	assert(getPrimesCount(5204119, 6405872) == 77093);
	assert(findNextPrime(6803514) == 6803521);

	//test #996
	assert(isPrime(903327) == 0);
	assert(getPrimesCount(1359860, 8467392) == 464812);
	assert(findNextPrime(903327) == 903337);

	//test #997
	assert(isPrime(6418503) == 0);
	assert(getPrimesCount(932349, 6860394) == 394104);
	assert(findNextPrime(6418503) == 6418507);

	//test #998
	assert(isPrime(2339787) == 0);
	assert(getPrimesCount(4010590, 5940900) == 125246);
	assert(findNextPrime(2339787) == 2339797);

	//test #999
	assert(isPrime(6025045) == 0);
	assert(getPrimesCount(5539597, 8280041) == 174012);
	assert(findNextPrime(6025045) == 6025079);

	//test #1000
	assert(isPrime(6831449) == 1);
	assert(getPrimesCount(1474563, 4594947) == 209764);
	assert(findNextPrime(6831449) == 6831449);

	//special test #1
	assert(isPrime(1) == 0);
	assert(getPrimesCount(8270496, 8270496) == 0);
	assert(findNextPrime(1) == 2);

	//special test #2
	assert(isPrime(0) == 0);
	assert(getPrimesCount(8226823, 8226823) == 0);
	assert(findNextPrime(0) == 2);

	//special test #3
	assert(isPrime(0) == 0);
	assert(getPrimesCount(1967940, 1967940) == 0);
	assert(findNextPrime(0) == 2);

	//special test #4
	assert(isPrime(2) == 1);
	assert(getPrimesCount(1466996, 1466996) == 0);
	assert(findNextPrime(2) == 2);

	//special test #5
	assert(isPrime(0) == 0);
	assert(getPrimesCount(4983342, 4983342) == 0);
	assert(findNextPrime(0) == 2);

	//special test #6
	assert(isPrime(2) == 1);
	assert(getPrimesCount(5161487, 5161487) == 0);
	assert(findNextPrime(2) == 2);

	//special test #7
	assert(isPrime(2) == 1);
	assert(getPrimesCount(2890319, 2890319) == 0);
	assert(findNextPrime(2) == 2);

	//special test #8
	assert(isPrime(0) == 0);
	assert(getPrimesCount(1069766, 1069766) == 0);
	assert(findNextPrime(0) == 2);

	//special test #9
	assert(isPrime(0) == 0);
	assert(getPrimesCount(8341505, 8341505) == 0);
	assert(findNextPrime(0) == 2);

	//special test #10
	assert(isPrime(0) == 0);
	assert(getPrimesCount(6946495, 6946495) == 0);
	assert(findNextPrime(0) == 2);

	//special test2 #1
	assert(isPrime(0) == 0);
	assert(getPrimesCount(0, 10000000) == 664579);
	assert(findNextPrime(0) == 2);

	//special test2 #2
	assert(isPrime(10000000) == 0);
	assert(getPrimesCount(0, 10000000) == 664579);
	assert(findNextPrime(10000000) == 10000019);

	//special test2 #3
	assert(isPrime(10000000) == 0);
	assert(getPrimesCount(0, 10000000) == 664579);
	assert(findNextPrime(10000000) == 10000019);

	//special test2 #4
	assert(isPrime(10000000) == 0);
	assert(getPrimesCount(0, 10000000) == 664579);
	assert(findNextPrime(10000000) == 10000019);

	//special test2 #5
	assert(isPrime(10000000) == 0);
	assert(getPrimesCount(10000000, 10000000) == 0);
	assert(findNextPrime(10000000) == 10000019);

	//special test2 #6
	assert(isPrime(0) == 0);
	assert(getPrimesCount(0, 10000000) == 664579);
	assert(findNextPrime(0) == 2);

	//special test2 #7
	assert(isPrime(0) == 0);
	assert(getPrimesCount(0, 10000000) == 664579);
	assert(findNextPrime(0) == 2);

	//special test2 #8
	assert(isPrime(10000000) == 0);
	assert(getPrimesCount(0, 0) == 0);
	assert(findNextPrime(10000000) == 10000019);

	//special test2 #9
	assert(isPrime(10000000) == 0);
	assert(getPrimesCount(0, 0) == 0);
	assert(findNextPrime(10000000) == 10000019);

	//special test2 #10
	assert(isPrime(10000000) == 0);
	assert(getPrimesCount(0, 10000000) == 664579);
	assert(findNextPrime(10000000) == 10000019);

	return 0;
}