#include "script_mod.hpp"
#include "script_macros.hpp"

class CfgPatches {
    class hlcweapons_core {
        requiredaddons[] = {"A3_Data_F_Destroyer_Loadorder","A3_Data_F_Sams_Loadorder","cba_main"}; //this covers all A3(v1.84) + CBA addons
        units[] = {};
        weapons[] = {};
        magazines[] = {};
        author="toadie";
		requiredVersion = REQUIRED_VERSION;
		versionDesc = "NIARMA - CORE";
		versionAct = "";
        version = "1.6";
    };
};
#include "CfgAmmo.hpp"  
#include "CfgMagazines.hpp"  
#include "CfgFunctions.hpp"
#include "CfgEventhandlers.hpp"
#include "cfgsoundshaders.hpp"
#include "cfgsoundset.hpp"
#include "Particles.hpp"
#include "CfgMagazineWells.hpp"
#include "RscInGameUI.hpp"

class asdg_MuzzleSlot;
class asdg_MuzzleSlot_762 : asdg_MuzzleSlot {
    class compatibleItems {
        hlc_muzzle_300blk_KAC = 1;
        hlc_muzzle_MAG58_Brake = 1;
    };
};
class asdg_MuzzleSlot_762MG : asdg_MuzzleSlot { // for 7.62, 6.5 and 5.56 universal mount MG suppressors
    class compatibleItems {
        hlc_muzzle_MAG58_Brake = 1;
    };
};
class asdg_MuzzleSlot_556 : asdg_MuzzleSlot { // for 5.56x45 universal mount suppressors
    class compatibleItems {
        hlc_muzzle_556NATO_KAC = 1;
        hlc_muzzle_556NATO_rotexiiic_tan = 1;
        hlc_muzzle_556NATO_rotexiiic_grey = 1;
        hlc_muzzle_556NATO_M42000 = 1;
    };
};
class asdg_MuzzleSlot_9MM : asdg_MuzzleSlot { // for 9x19mm universal mount pistol suppressors
    class compatibleItems {
        hlc_muzzle_Octane9 = 1;
        hlc_muzzle_Evo9 = 1;
        hlc_muzzle_TiRant9 = 1;
        hlc_muzzle_TiRant9S = 1;
    };
};
class asdg_MuzzleSlot_45ACP : asdg_MuzzleSlot {
    class compatibleItems {
        hlc_muzzle_Octane45 = 1;
        hlc_muzzle_Evo40 = 1;
    };
};

class asdg_SlotInfo;
class asdg_OpticRail : asdg_SlotInfo{};
class asdg_PistolOpticMount: asdg_OpticRail {
class compatibleItems {
    hlc_optic_DocterV = 1;
    hlc_optic_RomeoV = 1;
};
};

class asdg_OpticRail1913 : asdg_OpticRail{
    class compatibleItems {
        hlc_optic_LeupoldM3A = 1;
        hlc_optic_ZF95Base = 1;
        hlc_optic_VOMZ3d = 1;
        hlc_optic_VOMZ = 1;
        hlc_optic_HensoldtZO_Hi = 1;
        hlc_optic_HensoldtZO_Hi_2D = 1;
        hlc_optic_HensoldtZO_lo = 1;
        hlc_optic_HensoldtZO_lo_2D = 1;
        hlc_optic_HensoldtZO_lo_Docter = 1;
        hlc_optic_HensoldtZO_lo_Docter_2D = 1;
        hlc_optic_HensoldtZO_Hi_Docter = 1;
        hlc_optic_HensoldtZO_Hi_Docter_2D = 1;
        HLC_optic_DocterR = 1;
        hlc_optic_ATACR_Offset = 1;
        hlc_optic_ATACR = 1;
    };
};
class UnderBarrelSlot;
class nia_rifle_gripod_slot : UnderBarrelSlot
{
    displayName = "Gripod slot";
    class compatibleItems
    {
    };
};
class asdg_UnderSlot : asdg_SlotInfo
{
    class compatibleItems {
        HLC_bipod_UTGShooters = 1;
        HLC_ISOPOD = 1;
    };
};
class nia_rifle_grips_slot : nia_rifle_gripod_slot
{
    linkProxy = "\hlc_core\mesh\nia_grip_proxy";
    class compatibleItems {
        //hlc_grip_AFG2 = 1;
        //hlc_grip_PMVFG = 1;
    };
};
class nia_rifle_bipodsgrips_slot :asdg_UnderSlot 
{
};
class PointerSlot;
class nia_charms_slot : PointerSlot
{
    displayName = "$STR_A3_PointerSlot0";
    iconPicture = "\a3\weapons_f\Data\ui\attachment_side";
    linkProxy = "\hlc_core\mesh\nia_charm_proxy";
    class compatibleItems
    {
        //The commented out ones are special patron ones. While I can't stop anyone with the wherewithall to compile a PBO from just uncommenting them and whatever, you know, keep it to yourself. 
        //HLC_Charm_Eurojank = 1;
        //HLC_Charm_NIArmsbacker = 1;
        //HLC_Charm_NIArmsbacker_dirty = 1;
        HLC_Charm_Izhmash = 1;
        HLC_Charm_Herstal = 1;
        HLC_Charm_Teethgang = 1;
    };
};

class asdg_PistolUnderRail : asdg_SlotInfo  {
    linkProxy = "\a3\data_f\proxies\weapon_slots\SIDE";
    displayName = "$STR_A3_PointerSlot0";
    iconPicture = "\a3\weapons_f\Data\ui\attachment_side";
    class compatibleItems {
        hlc_acc_TLR1 = 1;
        hlc_acc_DBALPL = 1;
        hlc_acc_DBALPL_FL=1;
    };
};
class CfgDistanceFilters
{
    class HLC_defaultDistanceFilter
    {
        type = "lowPassFilter";
        minCutoffFrequency = 150;
        qFactor = 1;
        innerRange = 400;
        range = 2600;
        powerFactor = 32;
    };
    class HLC_rifleTailDistanceFilter
    {
        type = "lowPassFilter";
        minCutoffFrequency = 150;
        qFactor = 1;
        innerRange = 350;
        range = 1800;
        powerFactor = 32;
    };
};
/*
Scripting notes- 


Weaponslotsinfo MASS is approximate to CENTAGRAMS... that is to say a mass of 7 is a mass of about 700 grams. Take consideration of this


1 MOA (inches) = Distance (yards) / 95.5
1 MOA (inches) = Distance (meters) / 87.3
1 MOA (centimeters) = Distance (yards) / 37.6
1 MOA (centimeters) = Distance (meters) / 34.4


Group size (inches) * 95.5 / Distance (yards) = Size of group in MOA

Group size (inches) * 87.3/ Distance (meters) = Size of group in MOA

Group size (centimeters) * 37.6/Distance (yards) = Size of group in MOA

Group size (centimeters) * 34.4/Distance (meters) = Size of group in MOA


So, 1 MOA is actually:
1.047" at 100 yards.
1.146" at 100 meters.
2.66 cm at 100 yards.
2.91 cm at 100 meters.

A half inch group at 100 yards would be a 0.478 MOA group.
The same size group at 125 meters would be a 0.35 MOA group.

class CfgMovesBasic
{
     class DefaultDie;
     class ManActions
     {
         FHQ_GestureReloadACR = "FHQ_GestureReloadACR";    
     };
    
    class Actions {
        class NoActions : ManActions {
            FHQ_GestureReloadACR[] = {"FHQ_GestureReloadACR", "Gesture"};
        };
    };
};
 
class CfgGesturesMale
{
    class Default;
     class States
     {
         class FHQ_GestureReloadACR: Default
         {
             file="\FHQ_Remington\ACR\data\anim\acr_reload.rtm";
             looped=0;
             speed=0.400000;
             mask="handsWeapon";
             headBobStrength=0.200000;
             headBobMode=2;
             rightHandIKBeg=1;
             rightHandIKEnd=1;
             leftHandIKCurve[]={0,1,0.050000,0,0.950000,0,1,1};
         };
     };
};




*/

class CfgMovesBasic {
     class DefaultDie;

     class ManActions {
        HLC_GestureRechamber3011 = "HLC_GestureRechamber3011";
        HLC_GestureReload3011 = "HLC_GestureReload3011";
        HLC_GestureReload3011_tac = "HLC_GestureReload3011_tac";
        HLC_GestureReload3011_20rnd = "HLC_GestureReload3011_20rnd";
        HLC_GestureReload3011_50rnd = "HLC_GestureReload3011_50rnd";
        HLC_GestureReloadAK = "HLC_GestureReloadAK";
        HLC_GestureReloadAK762 = "HLC_GestureReloadAK762";
        HLC_GestureReloadAK545OneHand= "HLC_GestureReloadAK545OneHand";
        HLC_GestureReloadAK545 = "HLC_GestureReloadAK545";
        HLC_GestureReloadAK762DRUM = "HLC_GestureReloadAK762DRUM";
        HLC_GestureReloadM60= "HLC_GestureReloadM60";
        HLC_GestureReloadSMLE= "HLC_GestureReloadSMLE";
        HLC_GestureReloadBoltSMLE= "HLC_GestureReloadBoltSMLE";
        HLC_GestureReloadAR15_BAD_WS="HLC_GestureReloadAR15_BAD_WS";
        HLC_GestureReloadAR15_BADX15_WS = "HLC_GestureReloadAR15_BAD_WS";
        HLC_GestureReloadAR15_BAD_DR="HLC_GestureReloadAR15_BAD_DR";
        HLC_GestureReloadAR15_catch_WS="HLC_GestureReloadAR15_catch_WS";
        HLC_GestureReloadAR15_X15 = "HLC_GestureReloadAR15_X15";
        HLC_GestureReloadAR15_catch_dr="HLC_GestureReloadAR15_catch_dr";
        HLC_GestureReloadG3SG1= "HLC_GestureReloadG3SG1";
        HLC_GestureReloadAUG= "HLC_GestureReloadAUG";
        HLC_GestureReloadAUGa3 = "HLC_GestureReloadAUGa3";
        HLC_GestureReloadRPK= "HLC_GestureReloadRPK";
        HLC_GestureReloadAK12= "HLC_GestureReloadAK12";
        HLC_GestureReloadGP30= "HLC_GestureReloadGP30";
        HLC_GestureReloadFALLONG= "HLC_GestureReloadFALLONG";
        HLC_GestureReloadMP5= "HLC_GestureReloadMP5";
        HLC_GestureReloadMP510= "HLC_GestureReloadMP510";
        HLC_GestureReloadMP5K= "HLC_GestureReloadMP5K";
        HLC_GestureReloadMP5K_pistol= "HLC_GestureReloadMP5K_pistol";
        HLC_GestureReloadM14= "HLC_GestureReloadM14";
        HLC_GestureReloadOSW= "HLC_GestureReloadOSW";
        HLC_GestureReloadHK53= "HLC_GestureReloadHK53";
        HLC_GestureReloadSten= "HLC_GestureReloadSten";
        HLC_GestureReloadAUGPara = "HLC_GestureReloadAUGPara";
        HLC_GestureSwapBarrelAUG = "HLC_GestureSwapBarrelAUG";
        HLC_GestureReloadp226 = "HLC_GestureReloadp226";
        HLC_GestureReloadSG550 = "HLC_GestureReloadSG550";
        HLC_GestureReloadSG553R = "HLC_GestureReloadSG553R";
        HLC_GestureReloadSG553RDrum = "HLC_GestureReloadSG553RDrum";
        HLC_GestureReloadGL5040 = "HLC_GestureReloadGL5040";
        NIA_GestureReload416 = "NIA_GestureReload416";
        NIA_GestureReload416_x15 = "NIA_GestureReload416_x15";
        NIA_GestureReload416_WS = "NIA_GestureReload416_WS";
        NIA_GestureReload416_BAD = "NIA_GestureReload416_BAD";
        NIA_GestureReloadAGC = "NIA_GestureReloadAGC";
        HLC_GestureReloadACRGL = "HLC_GestureReloadACRGL";
    };

    class Actions {
        class RifleBaseStandActions;
        class RifleAdjustProneBaseActions;

        class NoActions : ManActions {
            HLC_GestureRechamber3011[] = { "HLC_GestureRechamber3011", "Gesture" };
            HLC_GestureReload3011[] = { "HLC_GestureReload3011", "Gesture" };
            HLC_GestureReload3011_tac[] = { "HLC_GestureReload3011_tac", "Gesture" };
            HLC_GestureReload3011_20rnd[] = { "HLC_GestureReload3011_20rnd", "Gesture" };
            HLC_GestureReload3011_50rnd[] = { "HLC_GestureReload3011_50rnd", "Gesture" };
            HLC_GestureReloadAK[] = {"HLC_GestureReloadAK", "Gesture"};
            HLC_GestureReloadAK762[] = { "HLC_GestureReloadAK762", "Gesture" };
            HLC_GestureReloadAK545OneHand[] = { "HLC_GestureReloadAK545OneHand", "Gesture" };
            HLC_GestureReloadAK545[] = { "HLC_GestureReloadAK545", "Gesture" };
            HLC_GestureReloadAK762DRUM[] = { "HLC_GestureReloadAK762DRUM", "Gesture" };
            HLC_GestureReloadM60[] = {"HLC_GestureReloadM60", "Gesture"};
            HLC_GestureReloadSMLE[] =  {"HLC_GestureReloadSMLE", "Gesture"};
            HLC_GestureReloadBoltSMLE[] = {"HLC_GestureReloadBoltSMLE", "Gesture"};
            HLC_GestureReloadAR15_BAD_WS[]= {"HLC_GestureReloadAR15_BAD_WS", "Gesture"};
            HLC_GestureReloadAR15_BADX15_WS[] = { "HLC_GestureReloadAR15_BADX15_WS", "Gesture" };
            HLC_GestureReloadAR15_BAD_DR[]= {"HLC_GestureReloadAR15_BAD_dr", "Gesture"};
            HLC_GestureReloadAR15_catch_WS[]= {"HLC_GestureReloadAR15_catch_ws", "Gesture"};
            HLC_GestureReloadAR15_X15[] = { "HLC_GestureReloadAR15_X15", "Gesture" };
            HLC_GestureReloadAR15_catch_DR[]= {"HLC_GestureReloadAR15_catch_dr", "Gesture"};
            HLC_GestureReloadG3SG1[]= {"HLC_GestureReloadG3SG1", "Gesture"};
            HLC_GestureReloadHK53[]= {"HLC_GestureReloadHK53", "Gesture"};
            HLC_GestureReloadAUG[]= {"HLC_GestureReloadAUG","Gesture"};
            HLC_GestureReloadRPK[]= {"HLC_GestureReloadRPK","Gesture"};
            HLC_GestureReloadAK12[]= {"HLC_GestureReloadAK12", "Gesture"};
            HLC_GestureReloadGP30[]= {"HLC_GestureReloadGP30", "Gesture"};
            HLC_GestureReloadFALLONG[]= {"HLC_GestureReloadFALLONG", "Gesture"};
            HLC_GestureReloadMP5[]= {"HLC_GestureReloadMP5", "Gesture"};
            HLC_GestureReloadMP510[]= {"HLC_GestureReloadMP510", "Gesture"};
            HLC_GestureReloadMP5K[]= {"HLC_GestureReloadMP5K", "Gesture"};
            HLC_GestureReloadMP5K_pistol[]= {"HLC_GestureReloadMP5K_pistol", "Gesture"};
            HLC_GestureReloadM14[]= {"HLC_GestureReloadM14", "Gesture"};
            HLC_GestureReloadOSW[]= {"HLC_GestureReloadOSW", "Gesture"};
            HLC_GestureReloadSten[]= {"HLC_GestureReloadSten", "Gesture"};
            HLC_GestureReloadAUGPara[] = { "HLC_GestureReloadAUGPara", "Gesture" };
            HLC_GestureReloadAUGa3[] = { "HLC_GestureReloadAUGa3", "Gesture" };
            HLC_GestureSwapBarrelAUG[] = { "HLC_GestureSwapBarrelAUG", "Gesture" };
            HLC_GestureReloadp226[] = { "HLC_GestureReloadp226", "Gesture" };
            HLC_GestureReloadSG550[] = { "HLC_GestureReloadSG550", "Gesture" };
            HLC_GestureReloadSG553R[] = { "HLC_GesturereloadSG553R", "Gesture" };
            HLC_GestureReloadSG553RDrum[] = { "HLC_GestureReloadSG553RDrum", "Gesture" };
            HLC_GestureReloadGL5040[] = { "HLC_GestureReloadGL5040", "Gesture" };
            NIA_GestureReload416[] = { "NIA_GestureReload416", "Gesture" };
            NIA_GestureReload416_x15[] = { "NIA_GestureReload416_x15", "Gesture" };
            NIA_GestureReload416_WS[] = { "NIA_GestureReload416_WS", "Gesture" };
            NIA_GestureReload416_BAD[] = { "NIA_GestureReload416_BAD", "Gesture" };
            NIA_GestureReloadAGC[] = { "NIA_GestureReloadAGC", "Gesture" };
            HLC_GestureReloadACRGL[] = { "HLC_GestureReloadACRGL", "Gesture" };

        };

        class RifleProneActions : RifleBaseStandActions {
            HLC_GestureRechamber3011[] = { "HLC_GestureRechamber3011_Prone", "Gesture" };
            HLC_GestureReload3011[] = { "HLC_GestureReload3011_Prone", "Gesture" };
            HLC_GestureReload3011_tac[] = { "HLC_GestureReload3011_tac_Prone", "Gesture" };
            HLC_GestureReload3011_20rnd[] = { "HLC_GestureReload3011_20rnd_Prone", "Gesture" };
            HLC_GestureReload3011_50rnd[] = { "HLC_GestureReload3011_50rnd_Prone", "Gesture" };
            HLC_GestureReloadM60[] = {"HLC_GestureReloadM60_Prone","Gesture"};
            HLC_GestureReloadRPK[]= {"HLC_GestureReloadRPK_Prone","Gesture"};
            HLC_GestureReloadAK[]= {"HLC_GestureReloadAK_Prone","Gesture"};
            HLC_GestureReloadAK762[] = { "HLC_GestureReloadAK762_Prone", "Gesture" };
            HLC_GestureReloadAK545[] = { "HLC_GestureReloadAK545_Prone", "Gesture" };
            HLC_GestureReloadAK545OneHand[] = { "HLC_GestureReloadAK545OneHand_Prone", "Gesture" };
            HLC_GestureReloadAK762DRUM[] = { "HLC_GestureReloadAK762DRUM_Prone", "Gesture" };
            HLC_GestureReloadAK12[]= {"HLC_GestureReloadAK12_Prone", "Gesture"};
            HLC_GestureReloadAKLONG[] = {"HLC_GestureReloadAK12_Prone","Gesture"};
            HLC_GestureReloadG3SG1[] = {"HLC_GestureReloadG3SG1_prone","Gesture"};
            HLC_GestureReloadAR15_BAD_WS[] = {"HLC_GestureReloadAR15_Prone","Gesture"};
            HLC_GestureReloadAR15_BADX15_WS[] = { "HLC_GestureReloadAR15_BADX15_WS_Prone", "Gesture" };
            HLC_GestureReloadAR15_BAD_DR[] = {"HLC_GestureReloadAR15_Prone","Gesture"};
            HLC_GestureReloadAR15_catch_WS[] = {"HLC_GestureReloadAR15_Prone","Gesture"};
            HLC_GestureReloadAR15_X15[] = { "HLC_GestureReloadAR15_X15", "Gesture" };
            HLC_GestureReloadAR15_catch_DR[] = {"HLC_GestureReloadAR15_Prone","Gesture"};
            HLC_GestureReloadAUG[] = { "HLC_GestureReloadAUG_Prone", "Gesture" };
            HLC_GestureReloadAUGa3[] = { "HLC_GestureReloadAUGa3_prone", "Gesture" };
            HLC_GestureReloadGP30[] = {"HLC_GestureReloadGP30_Prone","Gesture"};
            HLC_GestureReloadMP5[]= {"HLC_GestureReloadMP5_Prone", "Gesture"};
            HLC_GestureReloadMP510[]= {"HLC_GestureReloadMP510_Prone", "Gesture"};
            HLC_GestureReloadMP5K[]= {"HLC_GestureReloadMP5K_Prone", "Gesture"};
            HLC_GestureReloadMP5K_pistol[]= {"HLC_GestureReloadMP5K_pistol_prone", "Gesture"};
            HLC_GestureReloadM14[]= {"HLC_GestureReloadM14_Prone", "Gesture"};
            HLC_GestureReloadHK53[]= {"HLC_GestureReloadHK53_Prone", "Gesture"};
            HLC_GestureReloadOSW[]= {"HLC_GestureReloadOSW_Prone", "Gesture"};
            HLC_GestureReloadFALLONG[]= {"HLC_GestureReloadFALLONG_prone", "Gesture"};
            HLC_GestureReloadAUGPara[] = { "HLC_GestureReloadAUGPara_Prone", "Gesture" };
            HLC_GestureSwapBarrelAUG[] = { "HLC_GestureSwapBarrelAUG_prone", "Gesture" };
            HLC_GestureReloadp226[] = { "HLC_GestureReloadp226_prone", "Gesture" };
            HLC_GestureReloadSG550[] = { "HLC_GestureReloadSG550_prone", "Gesture" };
            HLC_GesturereloadSG553R[] = { "HLC_GesturereloadSG553R_prone", "Gesture" };
            HLC_GestureReloadSG553RDrum[] = { "HLC_GestureReloadSG553RDrum_prone", "Gesture" };
            HLC_GestureReloadGL5040[] = { "HLC_GestureReloadGL5040_prone", "Gesture" };
            NIA_GestureReload416[] = { "NIA_GestureReload416_Prone", "Gesture" };
            NIA_GestureReload416_x15[] = { "NIA_GestureReload416_x15_Prone", "Gesture" };
            NIA_GestureReload416_WS[] = { "NIA_GestureReload416_WS_Prone", "Gesture" };
            NIA_GestureReload416_BAD[] = { "NIA_GestureReload416_BAD_Prone", "Gesture" };
            NIA_GestureReloadAGC[] = { "NIA_GestureReloadAGC_Prone", "Gesture" };
            HLC_GestureReloadACRGL[] = { "HLC_GestureReloadACRGL_Prone", "Gesture" };
        };

        class RifleAdjustRProneActions : RifleAdjustProneBaseActions {
            HLC_GestureRechamber3011[] = { "HLC_GestureRechamber3011_Context", "Gesture" };
            HLC_GestureReload3011[] = { "HLC_GestureReload3011_Context", "Gesture" };
            HLC_GestureReload3011_tac[] = { "HLC_GestureReload3011_tac_Context", "Gesture" };
            HLC_GestureReload3011_20rnd[] = { "HLC_GestureReload3011_20rnd_Context", "Gesture" };
            HLC_GestureReload3011_50rnd[] = { "HLC_GestureReload3011_50rnd_Context", "Gesture" };
            HLC_GestureReloadM60[] = {"HLC_GestureReloadM60_Context","Gesture"};
            HLC_GestureReloadAK[] = {"HLC_GestureReloadAK_Context","Gesture"};
            HLC_GestureReloadAK762[] = { "HLC_GestureReloadAK762_Context", "Gesture" };
            HLC_GestureReloadAK545[] = { "HLC_GestureReloadAK545_Context", "Gesture" };
            HLC_GestureReloadAK545OneHand[] = { "HLC_GestureReloadAK545OneHand_Context", "Gesture" };
            HLC_GestureReloadAK762DRUM[] = { "HLC_GestureReloadAK762DRUM_Context", "Gesture" };
            HLC_GestureReloadRPK[] = {"HLC_GestureReloadRPK_Context","Gesture"};
            HLC_GestureReloadAK12[] = {"HLC_GestureReloadAK12_Context","Gesture"};
            HLC_GestureReloadAKLONG[] = {"HLC_GestureReloadAK_LongContext","Gesture"};
            HLC_GestureReloadGP30[]= {"HLC_GestureReloadGP30", "Gesture"};
            HLC_GestureReloadHK53[]= {"HLC_GestureReloadHK53_Context", "Gesture"};
            HLC_GestureReloadG3SG1[]= {"HLC_GestureReloadG3SG1_Context", "Gesture"};
            HLC_GestureReloadOSW[]= {"HLC_GestureReloadOSW_Context", "Gesture"};
            HLC_GestureReloadM14[]= {"HLC_GestureReloadM14_Context", "Gesture"};
            HLC_GestureReloadMP5[]= {"HLC_GestureReloadMP5_Context", "Gesture"};
            HLC_GestureReloadMP510[]= {"HLC_GestureReloadMP510_Context", "Gesture"};
            HLC_GestureReloadMP5K[]= {"HLC_GestureReloadMP5k_Context", "Gesture"};
            HLC_GestureReloadMP5K_pistol[]= {"HLC_GestureReloadMP5K_pistol_prone", "Gesture"};
            HLC_GestureReloadFALLONG[]= {"HLC_GestureReloadFALLONG_context", "Gesture"};
            HLC_GestureReloadAR15_BAD_WS[] = {"HLC_GestureReloadAR15_BAD_WS_Context","Gesture"};
            HLC_GestureReloadAR15_BADX15_WS[] = { "HLC_GestureReloadAR15_BADX15_WS_context", "Gesture" };
            HLC_GestureReloadAR15_BAD_DR[] = {"HLC_GestureReloadAR15_BAD_DR_Context","Gesture"};
            HLC_GestureReloadAR15_catch_WS[] = {"HLC_GestureReloadAR15_catch_WS_Context","Gesture"};
            HLC_GestureReloadAR15_catch_DR[] = {"HLC_GestureReloadAR15_catch_DR_Context","Gesture"};
            HLC_GestureReloadAUG[] = { "HLC_GestureReloadAUG_context", "Gesture" };
            HLC_GestureReloadAUGPara[] = { "HLC_GestureReloadAUGPara_context", "Gesture" };
            HLC_GestureSwapBarrelAUG[] = { "HLC_GestureSwapBarrelAUG_context", "Gesture" };
            HLC_GestureReloadp226[] = { "HLC_GestureReloadp226_context", "Gesture" };
            HLC_GestureReloadSG550[] = { "HLC_GestureReloadSG550_context", "Gesture" };
            HLC_GesturereloadSG553R[] = { "HLC_GesturereloadSG553R_context", "Gesture" };
            HLC_GestureReloadSG553RDrum[] = { "HLC_GestureReloadSG553RDrum_context", "Gesture" };
            HLC_GestureReloadGL5040[] = { "HLC_GestureReloadGL5040_context", "Gesture" };
            NIA_GestureReload416[] = { "NIA_GestureReload416_Context", "Gesture" };
            NIA_GestureReload416_x15[] = { "NIA_GestureReload416_x15_Context", "Gesture" };
            NIA_GestureReload416_WS[] = { "NIA_GestureReload416_WS_Context", "Gesture" };
            NIA_GestureReload416_BAD[] = { "NIA_GestureReload416_BAD_Context", "Gesture" };
            NIA_GestureReloadAGC[] = { "NIA_GestureReloadAGC_Context", "Gesture" };
            HLC_GestureReloadACRGL[] = { "HLC_GestureReloadACRGL_context", "Gesture" };
        };

        class RifleAdjustLProneActions : RifleAdjustProneBaseActions {
            HLC_GestureRechamber3011[] = { "HLC_GestureRechamber3011_Context", "Gesture" };
            HLC_GestureReload3011[] = { "HLC_GestureReload3011_Context", "Gesture" };
            HLC_GestureReload3011_tac[] = { "HLC_GestureReload3011_tac_Context", "Gesture" };
            HLC_GestureReload3011_20rnd[] = { "HLC_GestureReload3011_20rnd_context", "Gesture" };
            HLC_GestureReload3011_50rnd[] = { "HLC_GestureReload3011_50rnd_Context", "Gesture" };
            HLC_GestureReloadM60[] = {"HLC_GestureReloadM60_Context","Gesture"};
            HLC_GestureReloadAK[] = {"HLC_GestureReloadAK_Context","Gesture"};
            HLC_GestureReloadAK762[] = { "HLC_GestureReloadAK762_Context", "Gesture" };
            HLC_GestureReloadAK545[] = { "HLC_GestureReloadAK545_Context", "Gesture" };
            HLC_GestureReloadAK545OneHand[] = { "HLC_GestureReloadAK545OneHand_Context", "Gesture" };
            HLC_GestureReloadAK762DRUM[] = { "HLC_GestureReloadAK762DRUM_Context", "Gesture" };
            HLC_GestureReloadRPK[] = {"HLC_GestureReloadRPK_Context","Gesture"};
            HLC_GestureReloadAK12[] = {"HLC_GestureReloadAK12_Context","Gesture"};
            HLC_GestureReloadAKLONG[] = {"HLC_GestureReloadAK_LongContext","Gesture"};
            HLC_GestureReloadHK53[] = {"HLC_GestureReloadHK53_Context","Gesture"};
            HLC_GestureReloadG3SG1[]= {"HLC_GestureReloadG3SG1_Context", "Gesture"};
            HLC_GestureReloadOSW[]= {"HLC_GestureReloadOSW_Context", "Gesture"};
            HLC_GestureReloadM14[]= {"HLC_GestureReloadM14_Context", "Gesture"};
            HLC_GestureReloadMP5[]= {"HLC_GestureReloadMP5_Context", "Gesture"};
            HLC_GestureReloadMP510[]= {"HLC_GestureReloadMP510_Context", "Gesture"};
            HLC_GestureReloadMP5K[]= {"HLC_GestureReloadMP5k_Context", "Gesture"};
            HLC_GestureReloadMP5K_pistol[]= {"HLC_GestureReloadMP5K_pistol_prone", "Gesture"};
            HLC_GestureReloadFALLONG[]= {"HLC_GestureReloadFALLONG_context", "Gesture"};
            HLC_GestureReloadAR15_BAD_WS[] = {"HLC_GestureReloadAR15_BAD_WS_Context","Gesture"};
            HLC_GestureReloadAR15_BADX15_WS[] = { "HLC_GestureReloadAR15_BADX15_WS_context", "Gesture" };
            HLC_GestureReloadAR15_BAD_DR[] = {"HLC_GestureReloadAR15_BAD_DR_Context","Gesture"};
            HLC_GestureReloadAR15_catch_WS[] = {"HLC_GestureReloadAR15_catch_WS_Context","Gesture"};
            HLC_GestureReloadAR15_catch_DR[] = {"HLC_GestureReloadAR15_catch_DR_Context","Gesture"};
            HLC_GestureReloadAUG[] = { "HLC_GestureReloadAUG_context", "Gesture" };
            HLC_GestureReloadAUGPara[] = { "HLC_GestureReloadAUGPara_context", "Gesture" };
            HLC_GestureSwapBarrelAUG[] = { "HLC_GestureSwapBarrelAUG_context", "Gesture" };
            HLC_GestureReloadp226[] = { "HLC_GestureReloadp226_context", "Gesture" };
            HLC_GestureReloadSG550[] = { "HLC_GestureReloadSG550_context", "Gesture" };
            HLC_GesturereloadSG553R[] = { "HLC_GestureReloadSG553R_context", "Gesture" };
            HLC_GestureReloadSG553RDrum[] = { "HLC_GestureReloadSG553RDrum_context", "Gesture" };
            HLC_GestureReloadGL5040[] = { "HLC_GestureReloadGL5040_context", "Gesture" };
            NIA_GestureReload416[] = { "NIA_GestureReload416_Context", "Gesture" };
            NIA_GestureReload416_x15[] = { "NIA_GestureReload416_x15_Context", "Gesture" };
            NIA_GestureReload416_WS[] = { "NIA_GestureReload416_WS_Context", "Gesture" };
            NIA_GestureReload416_BAD[] = { "NIA_GestureReload416_BAD_Context", "Gesture" };
            NIA_GestureReloadAGC[] = { "NIA_GestureReloadAGC_Context", "Gesture" };
            HLC_GestureReloadACRGL[] = { "HLC_GestureReloadACRGL_context", "Gesture" };
        };

        class RifleAdjustFProneActions : RifleAdjustProneBaseActions {
            HLC_GestureRechamber3011[] = { "HLC_GestureRechamber3011", "Gesture" };
            HLC_GestureReload3011[] = { "HLC_GestureReload3011", "Gesture" };
            HLC_GestureReload3011_tac[] = { "HLC_GestureReload3011_tac", "Gesture" };
            HLC_GestureReload3011_20rnd[] = { "HLC_GestureReload3011_20rnd", "Gesture" };
            HLC_GestureReload3011_50rnd[] = { "HLC_GestureReload3011_50rnd", "Gesture" };
            HLC_GestureReloadM60[] = {"HLC_GestureReloadM60","Gesture"};
            HLC_GestureReloadAK[] = {"HLC_GestureReloadAK","Gesture"};
            HLC_GestureReloadAK762[] = { "HLC_GestureReloadAK762", "Gesture" };
            HLC_GestureReloadAK545[] = { "HLC_GestureReloadAK545", "Gesture" };
            HLC_GestureReloadAK545OneHand[] = { "HLC_GestureReloadAK545OneHand", "Gesture" };
            HLC_GestureReloadAK762Drum[] = { "HLC_GestureReloadAK762Drum", "Gesture" };
            HLC_GestureReloadRPK[] = {"HLC_GestureReloadRPK","Gesture"};
            HLC_GestureReloadAK12[] = {"HLC_GestureReloadAK12","Gesture"};
            HLC_GestureReloadAKLONG[] = {"HLC_GestureReloadAK12","Gesture"};
            HLC_GestureReloadGP30[]= {"HLC_GestureReloadGP30", "Gesture"};
            HLC_GestureReloadG3SG1[]= {"HLC_GestureReloadG3SG1", "Gesture"};
            HLC_GestureReloadOSW[]= {"HLC_GestureReloadOSW", "Gesture"};
            HLC_GestureReloadM14[]= {"HLC_GestureReloadM14", "Gesture"};
            HLC_GestureReloadMP5[]= {"HLC_GestureReloadMP5", "Gesture"};
            HLC_GestureReloadMP510[]= {"HLC_GestureReloadMP510", "Gesture"};
            HLC_GestureReloadMP5K[]= {"HLC_GestureReloadMP5k", "Gesture"};
            HLC_GestureReloadMP5K_pistol[]= {"HLC_GestureReloadMP5K_pistol", "Gesture"};
            HLC_GestureReloadFALLONG[]= {"HLC_GestureReloadFALLONG", "Gesture"};
            HLC_GestureReloadAR15_BAD_WS[]= {"HLC_GestureReloadAR15_BAD_WS", "Gesture"};
            HLC_GestureReloadAR15_BADX15_WS[] = { "HLC_GestureReloadAR15_BADX15_WS", "Gesture" };
            HLC_GestureReloadAR15_BAD_DR[]= {"HLC_GestureReloadAR15_BAD_dr", "Gesture"};
            HLC_GestureReloadAR15_catch_WS[]= {"HLC_GestureReloadAR15_catch_ws", "Gesture"};
            HLC_GestureReloadAR15_catch_DR[]= {"HLC_GestureReloadAR15_catch_dr", "Gesture"};
            HLC_GestureReloadAUG[] = { "HLC_GestureReloadAUG", "Gesture" };
            HLC_GestureReloadAUGPara[] = { "HLC_GestureReloadAUGPara", "Gesture" };
            HLC_GestureSwapBarrelAUG[] = { "HLC_GestureSwapBarrelAUG", "Gesture" };
            HLC_GestureReloadp226[] = { "HLC_GestureReloadp226", "Gesture" };
            HLC_GestureReloadSG550[] = { "HLC_GestureReloadSG550", "Gesture" };
            HLC_GesturereloadSG553R[] = { "HLC_GesturereloadSG553R", "Gesture" };
            HLC_GestureReloadSG553RDrum[] = { "HLC_GestureReloadSG553RDrum", "Gesture" };
            HLC_GestureReloadGL5040[] = { "HLC_GestureReloadGL5040", "Gesture" };
            NIA_GestureReload416[] = { "NIA_GestureReload416", "Gesture" };
            NIA_GestureReload416_x15[] = { "NIA_GestureReload416_x15", "Gesture" };
            NIA_GestureReload416_WS[] = { "NIA_GestureReload416_WS", "Gesture" };
            NIA_GestureReload416_BAD[] = { "NIA_GestureReload416_BAD", "Gesture" };
            NIA_GestureReloadAGC[] = { "NIA_GestureReloadAGC", "Gesture" };
            HLC_GestureReloadACRGL[] = { "HLC_GestureReloadACRGL", "Gesture" };
        };
    };
};

class CfgGesturesMale {
    class Default;
    class GestureReloadBase;

    class States {
        class HLC_GestureReloadAK : Default {
            file="\hlc_core\animation\gesture\reload_ak_onehanded.rtm";
            looped=0;
            speed = 0.23076923076923076923076923076923;
            mask="handsWeapon";
            // mask="empty";
            headBobStrength=0.200000;
            headBobMode=2;
            leftHandIKBeg = false;
            leftHandIKCurve[] = {0, 1, 0.075, 0, 0.85, 0, 0.93, 1};
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = {1};
            rightHandIKEnd = true;
        };
        class HLC_GestureReloadAK_prone : Default {
            file = "\hlc_core\animation\gesture\reload_ak_prone.rtm";
            looped = 0;
            speed = -4.8;
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.2;
            headBobMode = 2;
            leftHandIKBeg = false;
            leftHandIKCurve[] = { 0, 1, 0.075, 0, 0.85, 0, 0.93, 1 };
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = { 1 };
            rightHandIKEnd = true;
        };
        class HLC_GestureReloadAK_Context : HLC_GestureReloadAK {
            mask = "handsWeapon_context";
        };
        class HLC_GestureReloadAK545OneHand : Default {
            file = "\hlc_core\animation\gesture\reload_ak545onehand_standing.rtm";
            looped = 0;
            speed = -4.8;
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.200000;
            headBobMode = 2;
            leftHandIKBeg = false;
            leftHandIKCurve[] = { 0, 1, 0.075, 0, 0.85, 0, 0.93, 1 };
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = { 1 };
            rightHandIKEnd = true;
        };
        class HLC_GestureReloadAK545OneHand_prone : Default {
            file = "\hlc_core\animation\gesture\reload_ak_prone.rtm";
            looped = 0;
            speed = -4.8;
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.2;
            headBobMode = 2;
            leftHandIKBeg = false;
            leftHandIKCurve[] = { 0, 1, 0.075, 0, 0.85, 0, 0.93, 1 };
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = { 1 };
            rightHandIKEnd = true;
        };
        class HLC_GestureReloadAK545OneHand_Context : HLC_GestureReloadAK545OneHand {
            mask = "handsWeapon_context";
        };
        class HLC_GestureReloadAK545 : Default {
            file = "\hlc_core\animation\gesture\reload_ak545_standing.rtm";
            looped = 0;
            speed = -4.8;
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.200000;
            headBobMode = 2;
            rightHandIKCurve[] = { 0.631944, 1, 0.657922, 0, 0.840278, 0, 0.875, 1 };
            leftHandIKCurve[] = { 0, 1, 0.03125, 0, 0.868056, 0, 0.96, 1 };
            leftHandIKBeg = false;
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKEnd = true;
        };
        class HLC_GestureReloadAK545_prone : Default {
            file = "\hlc_core\animation\gesture\reload_ak_prone.rtm";
            looped = 0;
            speed = -4.8;
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.2;
            headBobMode = 2;
            leftHandIKBeg = false;
            leftHandIKCurve[] = { 0, 1, 0.075, 0, 0.85, 0, 0.93, 1 };
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = { 1 };
            rightHandIKEnd = true;
        };
        class HLC_GestureReloadAK545_Context : HLC_GestureReloadAK545 {
            mask = "handsWeapon_context";
        };
        class HLC_GestureReloadAK762 : Default {
            file = "\hlc_core\animation\gesture\reload_ak762_standing.rtm";
            looped = 0;
            speed = -4.8;
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.200000;
            headBobMode = 2;
            rightHandIKCurve[] = { 0.631944, 1, 0.657922, 0, 0.840278, 0, 0.875, 1 };
            leftHandIKCurve[] = { 0, 1, 0.03125, 0, 0.868056, 0, 0.96, 1 };
            leftHandIKBeg = false;
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKEnd = true;
        };
        class HLC_GestureReloadAK762_prone : Default {
            file = "\hlc_core\animation\gesture\reload_ak762_prone.rtm";
            looped = 0;
            speed = -4.8;
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.2;
            headBobMode = 2;
            leftHandIKBeg = false;
            leftHandIKCurve[] = { 0, 1, 0.075, 0, 0.868, 0, 0.96, 1 };
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = { 0, 1, 0.027778, 0, 0.84, 0, 0.86, 1 };
            rightHandIKEnd = true;
        };
        class HLC_GestureReloadAK762_Context : HLC_GestureReloadAK762 {
            mask = "handsWeapon_context";
        };
        class HLC_GestureReloadAK762Drum : Default {
            file = "\hlc_core\animation\gesture\reload_ak762drum_standing.rtm";
            looped = 0;
            speed = -5.833333;
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.200000;
            headBobMode = 2;
            rightHandIKCurve[] = { 0.67428, 1, 0.702857, 0, 0.88, 0, 0.90857, 1 };
            leftHandIKCurve[] = { 0, 1, 0.03125, 0, 0.91428, 0, 0.96, 1 };
            leftHandIKBeg = false;
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKEnd = true;
        };
        class HLC_GestureReloadAK762Drum_prone : Default {
            file = "\hlc_core\animation\gesture\reload_ak76drum_prone.rtm";
            looped = 0;
            speed = -5.833333;
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.02;
            headBobMode = 2;
            leftHandIKBeg = false;
            leftHandIKCurve[] = { 0, 1, 0.075, 0, 0.85, 0, 0.93, 1 };
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = { 1 };
            rightHandIKEnd = true;
        };
        class HLC_GestureReloadAK762Drum_Context : HLC_GestureReloadAK762Drum {
            mask = "handsWeapon_context";
        };
        class HLC_GestureReloadM60 : Default {
            file="hlc_core\animation\gesture\reload_m60e4_standing.rtm";
            looped=0;
            speed=0.09090909090909090909090909090909;
            mask="handsWeapon";
            // mask="empty";
            headBobStrength=0.25;
            headBobMode=2;
            leftHandIKBeg = true;
            leftHandIKCurve[] = {0.3, 1, 0.340, 0, 0.945, 0, 0.98, 1};
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = {0, 1, 0.0455, 0, 0.3, 0, 0.334, 1};
            rightHandIKEnd = true;
        };
        class HLC_GestureReloadM60_Context : HLC_GestureReloadM60 {
            mask = "handsWeapon_context";
        };

        class HLC_GestureReloadM60_Prone : Default {
            file="hlc_core\animation\gesture\reload_m60e4_prone.rtm";
            looped=0;
            speed=0.09090909090909090909090909090909;
            mask="handsWeapon";
            // mask="empty";
            headBobStrength=0.25;
            headBobMode=2;
            leftHandIKBeg = true;
            leftHandIKCurve[] = {0.3, 1, 0.340, 0, 0.945, 0, 0.98, 1};
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = {0, 1, 0.0455, 0, 0.3, 0, 0.334, 1};
            rightHandIKEnd = true;
        };
        class HLC_GestureReloadAR15_BAD_WS : Default {
            file = "hlc_core\animation\gesture\reload_ar15_BAD_workspace.rtm";
            looped=0;
            speed=0.3003000;
            mask="handsWeapon";
            // mask="empty";
            headBobStrength=0.1;
            headBobMode=2;
            leftHandIKBeg = true;
            leftHandIKCurve[] = {0, 1, 0.07, 0, 0.81, 0, 0.86, 1};
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = {0,1,0.08,0,0.14, 0, 0.17, 1,0.57,1,0.68,0,0.78,1};
            rightHandIKEnd = true;
        };
        class HLC_GestureReloadAR15_BADX15_WS : Default {
            file = "hlc_core\animation\gesture\reload_ar15X15_BAD_standing.rtm";
            looped = 0;
            speed = -2.766;
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.3;
            headBobMode = 2;
            leftHandIKBeg = true;
            leftHandIKCurve[] = { 0, 1, 0.07, 0, 0.81, 0, 0.86, 1 };
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = { 0, 1, 0.08, 0, 0.14, 0, 0.17, 1, 0.57, 1, 0.68, 0, 0.78, 1 };
            rightHandIKEnd = true;
        };
        class HLC_GestureReloadAR15_BADX15_WS_prone : Default {
            file="hlc_core\animation\gesture\reload_ar15_prone.rtm";
            looped=0;
            speed=0.25;
            mask="handsWeapon";
            // mask="empty";
            headBobStrength=0.05;
            headBobMode=2;
            leftHandIKBeg = true;
            leftHandIKCurve[] = {0, 1, 0.07, 0, 0.81, 0, 0.86, 1};
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = {0,1,0.08,0,0.14, 0, 0.17, 1,0.57,1,0.68,0,0.78,1};
            rightHandIKEnd = true;
        };
        class HLC_GestureReloadAR15_BADX15_WS_Context : HLC_GestureReloadAR15_BADX15_WS {
            mask = "handsWeapon_context";
        };
        class HLC_GestureReloadAR15_BAD_DR : Default {
            file="hlc_core\animation\gesture\reload_ar15_BAD_downrange.rtm";
            looped=0;
            speed=0.3003000;
            mask="handsWeapon";
            // mask="empty";
            headBobStrength=0.1;
            headBobMode=2;
            leftHandIKBeg = true;
            leftHandIKCurve[] = {0, 1, 0.07, 0, 0.81, 0, 0.86, 1};
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = {0,1,0.08,0,0.14, 0, 0.17, 1,0.57,1,0.68,0,0.78,1};
            rightHandIKEnd = true;
        };
        class HLC_GestureReloadAR15_catch_WS : Default
        {
            file="hlc_core\animation\gesture\reload_ar15_catch_workspace.rtm";
            looped=0;
            speed=0.25;
            mask="handsWeapon";
            // mask="empty";
            headBobStrength=0.05;
            headBobMode=2;
            leftHandIKBeg = true;
            leftHandIKCurve[] = {0, 1, 0.07, 0, 0.81, 0, 0.86, 1};
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = {0,1,0.08,0,0.14, 0, 0.17, 1,0.57,1,0.68,0,0.78,1};
            rightHandIKEnd = true;
        };
        class HLC_GestureReloadAR15_X15 : Default
        {
            file = "hlc_core\animation\gesture\reload_ar15X15_standing.rtm";
            looped = 0;
            speed = 0.25;
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.05;
            headBobMode = 2;
            leftHandIKBeg = true;
            leftHandIKCurve[] = { 0, 1, 0.07, 0, 0.81, 0, 0.86, 1 };
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = { 0, 1, 0.08, 0, 0.14, 0, 0.17, 1, 0.57, 1, 0.68, 0, 0.78, 1 };
            rightHandIKEnd = true;
        };
        class HLC_GestureReloadAR15_X15_prone : Default
        {
            file = "hlc_core\animation\gesture\reload_ar15_catch_workspace.rtm";
            looped = 0;
            speed = 0.25;
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.05;
            headBobMode = 2;
            leftHandIKBeg = true;
            leftHandIKCurve[] = { 0, 1, 0.07, 0, 0.81, 0, 0.86, 1 };
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = { 0, 1, 0.08, 0, 0.14, 0, 0.17, 1, 0.57, 1, 0.68, 0, 0.78, 1 };
            rightHandIKEnd = true;
        };
        class HLC_GestureReloadAR15_X15_Context : HLC_GestureReloadAR15_X15 {
            mask = "handsWeapon_context";
        };
        class HLC_GestureReloadAR15_Prone : Default {
            file="hlc_core\animation\gesture\reload_ar15_prone.rtm";
            looped=0;
            speed=0.25;
            mask="handsWeapon";
            // mask="empty";
            headBobStrength=0.05;
            headBobMode=2;
            leftHandIKBeg = true;
            leftHandIKCurve[] = {0, 1, 0.07, 0, 0.81, 0, 0.86, 1};
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = {0,1,0.08,0,0.14, 0, 0.17, 1,0.57,1,0.68,0,0.78,1};
            rightHandIKEnd = true;
        };

        class HLC_GestureReloadAR15_catch_DR : Default {
            file="hlc_core\animation\gesture\reload_ar15_catch_downrange.rtm";
            looped=0;
            speed=0.25;
            mask="handsWeapon";
            // mask="empty";
            headBobStrength=0.05;
            headBobMode=2;
            leftHandIKBeg = true;
            leftHandIKCurve[] = {0, 1, 0.07, 0, 0.81, 0, 0.86, 1};
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = {0,1,0.08,0,0.14, 0, 0.17, 1,0.57,1,0.68,0,0.78,1};
            rightHandIKEnd = true;
        };
        class HLC_GestureReloadAR15_catch_WS_Context : HLC_GestureReloadAR15_catch_WS {
            mask = "handsWeapon_context";
        };
        class HLC_GestureReloadAR15_BAD_DR_Context : HLC_GestureReloadAR15_BAD_DR {
            mask = "handsWeapon_context";
        };
        class HLC_GestureReloadAR15_BAD_WS_Context : HLC_GestureReloadAR15_BAD_WS {
            mask = "handsWeapon_context";
        };
        class HLC_GestureReloadAR15_catch_DR_Context : HLC_GestureReloadAR15_catch_DR {
            mask = "handsWeapon_context";
        };
        class HLC_GestureReloadSMLE : Default {
            file="hlc_core\animation\gesture\reload_enfield_standing.rtm";
            looped=0;
            speed=0.128;
            mask="handsWeapon";
            // mask="empty";
            headBobStrength=0.25;
            headBobMode=2;
            leftHandIKBeg = true;
            leftHandIKCurve[] = {1};
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = {0, 1, 0.00455, 0, 0.9488, 0, 1, 1};
            rightHandIKEnd = true;
        };
        class HLC_GestureReloadSMLE_Prone : Default {
            file="hlc_core\animation\gesture\reload_enfield_standing.rtm";
            looped=0;
            speed=0.128;
            mask="handsWeapon";
            // mask="empty";
            headBobStrength=0.25;
            headBobMode=2;
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = {0, 1, 0.0455, 0, 0.3, 0, 0.334, 1};
            rightHandIKEnd = true;
        };

        class HLC_GestureReloadBoltSMLE : Default {
            file="hlc_core\animation\gesture\rechamber_enfield.rtm";
            speed=0.77;
            looped = false;
            mask = "handsWeapon";
            headBobStrength=0.01;
            headBobMode=2;
            rightHandIKCurve[] = {0, 1, 0.04, 0, 0.90, 0, 1, 1};
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = {1};
        };
        class HLC_GestureReloadG3SG1 : Default {
            file="hlc_core\animation\gesture\reload_g3_stand.rtm";
            speed=-(180/30);
            looped = false;
            mask = "handsWeapon";
            headBobStrength=0.01;
            headBobMode=2;
            rightHandIKCurve[] = {1};
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = {0, 1, 0.033, 0, 0.86, 0, 0.9, 1};
        };
        class HLC_GestureReloadG3SG1_prone : Default {
            file="hlc_core\animation\gesture\reload_g3_prone.rtm";
            speed=0.16666666666666666666666666666667;
            looped = false;
            mask = "handsWeapon";
            headBobStrength=0.01;
            headBobMode=2;
            rightHandIKCurve[] = {1};
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = {0, 1, 0.033, 0, 0.86, 0, 0.9, 1};
        };
        class HLC_GestureReloadG3SG1_Context : HLC_GestureReloadG3SG1 {
            mask = "handsWeapon_context";
        };         
        class HLC_GestureReloadHK53 : Default {
            file="hlc_core\animation\gesture\reload_hk53_standing.rtm";
            speed=0.16666666666666666666666666666667;
            looped = false;
            mask = "handsWeapon";
            headBobStrength=0.01;
            headBobMode=2;
            rightHandIKCurve[] = {1};
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = {0, 1, 0.033, 0, 0.86, 0, 0.9, 1};
        };
        class HLC_GestureReloadHK53_prone : Default {
            file="hlc_core\animation\gesture\reload_hk53_prone.rtm";
            speed=0.16666666666666666666666666666667;
            looped = false;
            mask = "handsWeapon";
            headBobStrength=0.01;
            headBobMode=2;
            rightHandIKCurve[] = {1};
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = {0, 1, 0.033, 0, 0.86, 0, 0.9, 1};
        };
        class HLC_GestureReloadHK53_Context : HLC_GestureReloadHK53 {
            mask = "handsWeapon_context";
        };

        class HLC_GestureReloadAUG:Default {
            file="hlc_core\animation\gesture\reload_aug_stand.rtm";
            speed=0.18181818181818181818181818181818;
            looped = false;
            mask = "handsWeapon";
            headBobStrength=0.22;
            headBobMode=2;
            rightHandIKCurve[] = {1};
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = { 0, 1, 0.0363636363636, 0, 0.83636363636363636363636363636364, 0, 0.87272727272727272727272727272727, 1 };
        };
        class HLC_GestureReloadAUG_prone : Default {
            file = "hlc_core\animation\gesture\reload_aug_prone.rtm";
            speed = 0.18181818181818181818181818181818;
            looped = false;
            mask = "handsWeapon";
            headBobStrength = 0.22;
            headBobMode = 2;
            rightHandIKCurve[] = { 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = { 0, 1, 0.0363636363636, 0, 0.83636363636363636363636363636364, 0, 0.87272727272727272727272727272727, 1 };
        };
        class HLC_GestureReloadAUG_Context : HLC_GestureReloadAUG {
            mask = "handsWeapon_context";
        };

        class HLC_GestureSwapBarrelAUG : GestureReloadBase {
            file = "hlc_core\animation\gesture\barrelswap_aug_stand.rtm";
            speed = 0.21428571428571428571428571428571;
            looped = false;
            mask = "handsWeapon";
            weaponIK = 1;
            headBobStrength = 0.1;
            headBobMode = 2;
            canReload = 0;
            connectFrom[] = {};
            connectTo[] = {};
            interpolateWith[] = {};
            interpolateTo[] = {};
            interpolateFrom[] = {};
            aiming = "aimingDefault";
            aimingBody = "aimingUpDefault";
            rightHandIKBeg = true;
            rightHandIKEnd = true;
            rightHandIKCurve[] = { 0, 1 , 0.042857, 0, 0.8, 0, 0.842857, 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = { 0, 1, 0.07851, 1, 0.107143, 0, 0.721429, 0, 0.764286, 1 };
        };
        class HLC_GestureSwapBarrelAUG_prone : GestureReloadBase {
            file = "hlc_core\animation\gesture\barrelswap_aug_prone.rtm";
            speed = 0.21428571428571428571428571428571;
            looped = false;
            mask = "handsWeapon";
            weaponIK = 1;
            headBobStrength = 0.1;
            headBobMode = 2;
            canReload = 0;
            connectFrom[] = {};
            connectTo[] = {};
            interpolateWith[] = {};
            interpolateTo[] = {};
            interpolateFrom[] = {};
            rightHandIKBeg = true;
            rightHandIKEnd = true;
            rightHandIKCurve[] = { 0, 1, 0.042857, 0, 0.8, 0, 0.842857, 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = { 0, 1, 0.07851, 1, 0.107143, 0, 0.721429, 0, 0.764286, 1 };
        };
        class HLC_GestureSwapBarrelAUG_Context : HLC_GestureSwapBarrelAUG {
            mask = "handsWeapon_context";
        };
        class HLC_GestureReloadAUGa3 : Default {
            file = "hlc_core\animation\gesture\reload_auga3_stand.rtm";
            speed = 0.22727272727272727272727272727273;
            looped = false;
            mask = "handsWeapon";
            headBobStrength = 0.22;
            headBobMode = 2;
            rightHandIKCurve[] = { 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = { 0, 1, 0.0363636363636, 0, 0.83636363636363636363636363636364, 0, 0.87272727272727272727272727272727, 1 };
        };
        class HLC_GestureReloadAUGa3_prone : Default {
            file = "hlc_core\animation\gesture\reload_auga3_prone.rtm";
            speed = 0.22727272727272727272727272727273;
            looped = false;
            mask = "handsWeapon";
            headBobStrength = 0.1;
            headBobMode = 2;
            rightHandIKCurve[] = { 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = { 0, 1, 0.0363636363636, 0, 0.83636363636363636363636363636364, 0, 0.87272727272727272727272727272727, 1 };
        };
        class HLC_GestureReloadAUGa3_Context : HLC_GestureReloadAUGa3 {
            mask = "handsWeapon_context";
        };
        class HLC_GestureReloadAUGPara : Default {
            file = "hlc_core\animation\gesture\reload_augpara_stand.rtm";
            speed = 0.24;
            looped = false;
            mask = "handsWeapon";
            headBobStrength = 0.1;
            headBobMode = 2;
            rightHandIKCurve[] = { 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = { 0, 1, 0.048, 0, 0.84, 0, 0.88, 1 };
        };
        class HLC_GestureReloadAUGPara_prone : Default {
            file = "hlc_core\animation\gesture\reload_augpara_prone.rtm";
            speed = 0.24;
            looped = false;
            mask = "handsWeapon";
            headBobStrength = 0.3;
            headBobMode = 2;
            rightHandIKCurve[] = { 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = { 0, 1, 0.048, 0, 0.84, 0, 0.88, 1 };
        };
        class HLC_GestureReloadAUGPara_Context : HLC_GestureReloadAUGPara {
            mask = "handsWeapon_context";
        };
        class HLC_GestureReloadRPK:Default {
            file="hlc_core\animation\gesture\reload_rpk_standing.rtm";
            speed=0.1875;
            looped = false;
            mask = "handsWeapon";
            headBobStrength=0.2;
            headBobMode=2;
            rightHandIKCurve[] = {0.6125,1,0.675,0,0.85625,0,0.90625,1};
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = {0, 1, 0.03125, 0, 0.60625, 0, 0.625, 1};
        };

        class HLC_GestureReloadRPK_Prone : Default {
            file="hlc_core\animation\gesture\reload_rpk_prone.rtm";
            speed=0.1875;
            looped = false;
            mask = "handsWeapon";
            headBobStrength=0.02;
            headBobMode=2;
            rightHandIKCurve[] = {0.6125,1,0.675,0,0.85625,0,0.90625,1};
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = {0, 1, 0.03125, 0, 0.60625, 0, 0.625, 1};
        };
        class HLC_GestureReloadRPK_Context : HLC_GestureReloadRPK {
            mask = "handsWeapon_context";
        };
        class HLC_GestureReloadAK12 : Default {
            file="hlc_core\animation\gesture\reload_ak12_stand.rtm";
            speed=0.2;
            looped = false;
            mask = "handsWeapon";
            headBobStrength=0.2;
            headBobMode=2;
            rightHandIKCurve[] = {0.6533,1,0.66666667,0,0.793333,0,0.88,1};
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = {0, 1, 0.03125, 0, 0.58666666, 0, 0.64, 1};
        };
        class HLC_GestureReloadAK12_Prone : Default {
            file="hlc_core\animation\gesture\reload_ak12_prone.rtm";
            speed=0.2;
            looped = false;
            mask = "handsWeapon";
            headBobStrength=0.02;
            headBobMode=2;
            rightHandIKCurve[] = {0.6533,1,0.66666667,0,0.793333,0,0.88,1};
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = {0, 1, 0.03125, 0, 0.586666, 0, 0.64, 1};
        };
        class HLC_GestureReloadAK12_Context : HLC_GestureReloadAK12 {
            mask = "handsWeapon_context";
        };
        class HLC_GestureReloadAK12Prone_Context : HLC_GestureReloadAK12_Prone {
            mask = "handsWeapon_context";
        };
        class HLC_GestureReloadAK_Long : HLC_GestureReloadAK12 {
            file="hlc_core\animation\gesture\reload_ak_long.rtm";
        };
        class HLC_GestureReloadAK_LongProne : HLC_GestureReloadAK12_Prone {
            file="hlc_core\animation\gesture\reload_ak12_prone.rtm";
        };
        class HLC_GestureReloadAK_LongContext : HLC_GestureReloadAK_Long {
            mask = "handsWeapon_context";
        };
        class HLC_GestureReloadGP30 : Default {
            file="hlc_core\animation\gesture\reload_gp30.rtm";
            speed=0.42863266180882983283326189455637;
            looped = false;
            mask = "handsWeapon_context";
            headBobStrength=0.1;
            headBobMode=2;
            leftHandIKBeg = false;
            leftHandIKCurve[] = {0, 1, 0.075, 0, 0.65, 0, 0.74, 1};
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = {1};
            rightHandIKEnd = true;
        };
        class HLC_GestureReloadGP30_Prone : Default {
            file="hlc_core\animation\gesture\reload_gp30_prone.rtm";
            speed=0.42863266180882983283326189455637;
            looped = false;
            mask = "handsWeapon_context";
            headBobStrength=0.1;
            headBobMode=2;
            leftHandIKBeg = false;
            leftHandIKCurve[] = {0, 1, 0.075, 0, 0.65, 0, 0.74, 1};
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = {1};
            rightHandIKEnd = true;
        };
        class HLC_GestureReloadFALLONG : Default {
            file="hlc_core\animation\gesture\reload_fal_long.rtm";
            speed=0.18404907975460235612932364786722;
            looped = false;
            mask = "handsWeapon";
            headBobStrength=0.2;
            headBobMode=2;
            rightHandIKCurve[] = {1};
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = {0, 1, 0.03125, 0, 0.831, 0, 0.887, 1};
        };
        class HLC_GestureReloadFALLONG_prone : Default {
            file="hlc_core\animation\gesture\reload_fal_long_prone.rtm";
            speed=0.18404907975460235612932364786722;
            looped = false;
            mask = "handsWeapon";
            headBobStrength=0.2;
            headBobMode=2;
            rightHandIKCurve[] = {1};
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = {0, 1, 0.03125, 0, 0.89, 0, 0.9375, 1};
        };
        class HLC_GestureReloadFALLONG_Context : HLC_GestureReloadFALLONG {
            mask = "handsWeapon_context";
        };
        class HLC_GestureReloadOSW : Default {
            file="hlc_core\animation\gesture\reload_osw_standing.rtm";
            speed=0.23076923076923076923076923076923;
            looped = false;
            mask = "handsWeapon";
            headBobStrength=0.2;
            headBobMode=2;
            rightHandIKCurve[] = {1};
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = {0, 1,0.046154, 0, 0.938642, 0, 0.9724, 1};
        };
        class HLC_GestureReloadOSW_prone : Default {
            file="hlc_core\animation\gesture\reload_osw_prone.rtm";
            speed=0.23076923076923076923076923076923;
            looped = false;
            mask = "handsWeapon";
            headBobStrength=0.2;
            headBobMode=2;
            rightHandIKCurve[] = {1};
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = {0, 1,0.0902, 1, 0.127, 0, 0.93984, 0, 0.9924, 1};
        };
        class HLC_GestureReloadOSW_Context : HLC_GestureReloadOSW {
            mask = "handsWeapon_context";
        };
        class HLC_GestureReloadMP5 : Default {
            file="hlc_core\animation\gesture\reload_mp5_standing.rtm";
            speed=-(124/30);
            looped = false;
            mask = "handsWeapon";
            headBobStrength=0.2;
            headBobMode=2;
            rightHandIKCurve[] = {1};
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = {0, 1, 0.04166666, 0, 0.86666, 0, 0.9, 1};
        };
        class HLC_GestureReloadMP5_Prone : Default {
            file = "hlc_core\animation\gesture\reload_mp5_prone.rtm";
            speed = 0.25;
            looped = false;
            mask = "handsWeapon";
            headBobStrength = 0.2;
            headBobMode = 2;
            rightHandIKCurve[] = { 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = { 0, 1, 0.04166666, 0, 0.86666, 0, 0.9, 1 };
        };
        class HLC_GestureReloadMP5_Context : HLC_GestureReloadMP5 {
            mask = "handsWeapon_context";
        };
        class HLC_GestureReloadMP5K : Default {
            file="hlc_core\animation\gesture\reload_mp5K_standing.rtm";
            speed=0.260869;
            looped = false;
            mask = "handsWeapon";
            headBobStrength=0.1;
            headBobMode=2;
            rightHandIKCurve[] = {1};
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = {0, 1, 0.05217391, 0, 0.904347826, 0, 0.9391304347, 1};
        };
        class HLC_GestureReloadMP5K_prone : Default {
            file="hlc_core\animation\gesture\reload_mp5k_prone.rtm";
            speed=0.260869;
            looped = false;
            mask = "handsWeapon";
            headBobStrength=0.05;
            headBobMode=2;
            rightHandIKCurve[] = {1};
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = {0, 1, 0.05217391, 0, 0.904347826, 0, 0.9391304347, 1};
        };
        class HLC_GestureReloadMP5k_Context : HLC_GestureReloadMP5K {
            mask = "handsWeapon_context";
        };
        class HLC_GestureReloadMP5K_pistol : Default {
            file="hlc_core\animation\gesture\reload_mp5K_standing.rtm";
            speed=0.260869;
            looped = false;
            mask = "handsWeapon_pst";
            headBobStrength=0.1;
            showHandGun = 1;
            disableWeapons = 1;
            headBobMode=2;
            rightHandIKCurve[] = {1};
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = {0, 1, 0.05217391, 0, 0.904347826, 0, 0.9391304347, 1};
        };
        class HLC_GestureReloadMP5K_pistol_prone : HLC_GestureReloadMP5K_pistol {
            file="hlc_core\animation\gesture\reload_mp5k_prone.rtm";
            speed=0.260869;
            looped = false;
            mask = "handsWeapon_pst_context";
            headBobStrength=0.05;
            headBobMode=2;
            rightHandIKCurve[] = {1};
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = {0, 1, 0.05217391, 0, 0.904347826, 0, 0.9391304347, 1};
        };
        class HLC_GestureReloadMP5k_pistol_Context : HLC_GestureReloadMP5K_pistol_prone {
            mask = "handsWeapon_pst_context";
        };
        
        class HLC_GestureReloadMP510 : Default {
            file="hlc_core\animation\gesture\reload_mp510_standing.rtm";
            speed=0.3;
            looped = false;
            mask = "handsWeapon";
            headBobStrength=0.2;
            headBobMode=2;
            rightHandIKCurve[] = {1};
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = {0, 1, 0.05, 0, 0.77, 0, 0.91, 1};
        };
        class HLC_GestureReloadMP510_Prone : Default {
            file="hlc_core\animation\gesture\reload_mp510_prone.rtm";
            speed=0.3;
            looped = false;
            mask = "handsWeapon";
            headBobStrength=0.2;
            headBobMode=2;
            rightHandIKCurve[] = {1};
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = {0, 1, 0.05, 0, 0.77, 0, 0.91, 1};
        };
        class HLC_GestureReloadMP510_Context : HLC_GestureReloadMP510 {
            mask = "handsWeapon_context";
        };
        class HLC_GestureReloadM14 : Default {
            file = "hlc_core\animation\gesture\reload_m14_standing.rtm";
            speed = 0.23;
            looped = false;
            mask = "handsWeapon";
            headBobStrength = 0.2;
            headBobMode = 2;
            rightHandIKCurve[] = { 0, 1, 0.59, 1, 0.615384, 0, 0.7538, 0, 0.84615, 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = { 0, 1, 0.04166666, 0, 0.58416, 0, 0.615384, 1 };
        };
        class HLC_GestureReloadM14_Prone : Default {
            file = "hlc_core\animation\gesture\reload_m14_prone.rtm";
            speed = 0.23;
            looped = false;
            mask = "handsWeapon";
            headBobStrength = 0.2;
            headBobMode = 2;
            rightHandIKCurve[] = { 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = { 0, 1, 0.04166666, 0, 0.86666, 0, 0.9, 1 };
        };
        class HLC_GestureReloadM14_Context : HLC_GestureReloadM14 {
            mask = "handsWeapon_context";
        };

        class HLC_GestureReloadSten : Default {
            file="hlc_core\animation\gesture\reload_sten_standing.rtm";
            looped=0;
            speed=0.2112676056;
            mask="handsWeapon";
            headBobStrength=0.200000;
            headBobMode=2;
            leftHandIKCurve[]={0,1,0.1971830,1,0.204225,0,0.7957746,0,0.84507042,1};
            rightHandIKCurve[]={0,1,0.04929,0,0.16197,0,0.19718309,1};
        };
        class HLC_GestureReloadP226 : Default {
            file = "hlc_core\animation\gesture\reload_p226_standing.rtm";
            speed = -3.5;
            looped = false;
            mask = "handsWeapon_pst";
            headBobStrength = 0.2;
            headBobMode = 2;
            //rightHandIKCurve[] = { 0, 1, 0.02, 0, 0.92, 0, 0.96, 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = { 0, 1, 0.02, 0, 0.92, 0, 0.96, 1 };
        };
        class HLC_GestureReloadP226_Prone : Default {
            file = "hlc_core\animation\gesture\reload_p226_prone.rtm";
            speed = -3.5;
            looped = false;
            mask = "handsWeapon_pst";
            headBobStrength = 0.2;
            headBobMode = 2;
            rightHandIKCurve[] = { 0, 1, 0.02, 0, 0.92, 0, 0.96, 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = { 0, 1, 0.05, 0, 0.77, 0, 0.91, 1 };
        };
        class HLC_GestureReloadP226_Context : HLC_GestureReloadP226 {
            mask = "handsWeapon_context";
        };
        class HLC_GestureRechamber3011 : Default {
            file = "\hlc_core\animation\gesture\rechamber_3011_standing.rtm";
            looped = 0;
            speed = -2;
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.3;
            headBobMode = 2;
            rightHandIKCurve[] = { 0, 1, 0.06667, 0, 0.75, 0, 0.833333, 1 };
            leftHandIKCurve[] = { 0, 1, 1, 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKEnd = true;
        };
        class HLC_GestureRechamber3011_prone : Default {
            file = "\hlc_core\animation\gesture\rechamber_3011_prone.rtm";
            looped = 0;
            speed = -2;
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.1;
            headBobMode = 2;
            leftHandIKBeg = true;
            leftHandIKCurve[] = { 0, 1, 1, 1 };
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = { 0, 1, 0.06667, 0, 0.75, 0, 0.833333, 1 };
            rightHandIKEnd = true;
        };
        class HLC_GestureRechamber3011_Context : HLC_GestureRechamber3011 {
            mask = "handsWeapon_context";
        };
        class HLC_Gesturereload3011 : Default {
            file = "\hlc_core\animation\gesture\reload_3011_10rnd_standing.rtm";
            looped = 0;
            speed = -6;
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.3;
            headBobMode = 2;
            rightHandIKCurve[] = { 0, 1, 0.027778, 0, 0.90555556, 0, 0.9555556, 1 };
            leftHandIKCurve[] = { 0.155556, 1, 0.172228, 0, 0.7055556, 0, 0.738889, 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKEnd = true;
        };
        class HLC_Gesturereload3011_prone : Default {
            file = "\hlc_core\animation\gesture\reload_3011_10rnd_prone.rtm";
            looped = 0;
            speed = -6;
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.1;
            headBobMode = 2;
            leftHandIKBeg = true;
            leftHandIKCurve[] = { 0.155556, 1, 0.172228, 0, 0.7055556, 0, 0.738889, 1 };
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = { 0, 1, 0.027778, 0, 0.90555556, 0, 0.9555556, 1 };
            rightHandIKEnd = true;
        };
        class HLC_Gesturereload3011_Context : HLC_Gesturereload3011 {
            mask = "handsWeapon_context";
        };
        class HLC_Gesturereload3011_tac : Default {
            file = "\hlc_core\animation\gesture\reload_3011_10rnd_standing.rtm";
            looped = 0;
            speed = -6;
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.3;
            headBobMode = 2;
            leftHandIKCurve[] = { 0, 1, 0.027778, 0, 0.90555556, 0, 0.9555556, 1 };
            rightHandIKCurve[] = { 0, 1, 0.027778, 0, 0.1388889, 0, 0.1611, 1, 0.76444, 1, 0.783333, 0, 0.90555556, 0, 0.9555556, 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKEnd = true;
        };
        class HLC_Gesturereload3011_tac_prone : Default {
            file = "\hlc_core\animation\gesture\reload_3011_10rnd_prone.rtm";
            looped = 0;
            speed = -6;
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.1;
            headBobMode = 2;
            leftHandIKBeg = true;
            leftHandIKCurve[] = { 0.155556, 1, 0.172228, 0, 0.7055556, 0, 0.738889, 1 };
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = { 0, 1, 0.027778, 0, 0.1388889, 0, 0.1611, 1, 0.76444, 1, 0.783333, 0, 0.90555556, 0, 0.9555556, 1 };
            rightHandIKEnd = true;
        };
        class HLC_Gesturereload3011_tac_Context : HLC_Gesturereload3011_tac {
            mask = "handsWeapon_context";
        };
        class HLC_Gesturereload3011_20rnd : Default {
            file = "\hlc_core\animation\gesture\reload_3011_20rnd_standing.rtm";
            looped = 0;
            speed = -6;
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.3;
            headBobMode = 2;
            leftHandIKCurve[] = { 0, 1, 0.027778, 0, 0.90555556, 0, 0.9555556, 1 };
            rightHandIKCurve[] = { 0, 1, 0.027778, 0, 0.1388889, 0, 0.1611, 1, 0.76444, 1, 0.783333, 0, 0.90555556, 0, 0.9555556, 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKEnd = true;
        };
        class HLC_Gesturereload3011_20rnd_prone : Default {
            file = "\hlc_core\animation\gesture\reload_3011_20rnd_prone.rtm";
            looped = 0;
            speed = -6;
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.1;
            headBobMode = 2;
            leftHandIKBeg = true;
            leftHandIKCurve[] = { 0.155556, 1, 0.172228, 0, 0.7055556, 0, 0.738889, 1 };
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = { 0, 1, 0.027778, 0, 0.1388889, 0, 0.1611, 1, 0.76444, 1, 0.783333, 0, 0.90555556, 0, 0.9555556, 1 };
            rightHandIKEnd = true;
        };
        class HLC_Gesturereload3011_20rnd_Context : HLC_Gesturereload3011_20rnd {
            mask = "handsWeapon_context";
        };
        class HLC_Gesturereload3011_50rnd : Default {
            file = "\hlc_core\animation\gesture\reload_3011_50rnd_standing.rtm";
            looped = 0;
            speed = -6;
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.3;
            headBobMode = 2;
            leftHandIKCurve[] = { 0, 1, 0.027778, 0, 0.90555556, 0, 0.9555556, 1 };
            rightHandIKCurve[] = { 0, 1, 0.027778, 0, 0.1388889, 0, 0.1611, 1, 0.76444, 1, 0.783333, 0, 0.90555556, 0, 0.9555556, 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKEnd = true;
        };
        class HLC_Gesturereload3011_50rnd_prone : Default {
            file = "\hlc_core\animation\gesture\reload_3011_50rnd_prone.rtm";
            looped = 0;
            speed = -6;
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.1;
            headBobMode = 2;
            leftHandIKBeg = true;
            leftHandIKCurve[] = { 0.155556, 1, 0.172228, 0, 0.7055556, 0, 0.738889, 1 };
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKCurve[] = { 0, 1, 0.027778, 0, 0.1388889, 0, 0.1611, 1, 0.76444, 1, 0.783333, 0, 0.90555556, 0, 0.9555556, 1 };
            rightHandIKEnd = true;
        };
        class HLC_Gesturereload3011_50rnd_Context : HLC_Gesturereload3011_50rnd {
            mask = "handsWeapon_context";
        };
        class HLC_GesturereloadSG550 : Default {
            file = "\hlc_core\animation\gesture\reload_sg550_standing.rtm";
            looped = 0;
            speed = -4.133;
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.2;
            headBobMode = 2;
            rightHandIKCurve[] = { 0, 1, 1, 1 };
            leftHandIKCurve[] = { 0, 1, (4/124), 0, (108/124), 0, (117/124), 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKEnd = true;
        };
        class HLC_GesturereloadSG550_prone : Default {
            file = "hlc_core\animation\gesture\reload_sg550_prone.rtm";
            speed = -4.133;
            looped = false;
            mask = "handsWeapon";
            headBobStrength = 0.2;
            headBobMode = 2;
            rightHandIKCurve[] = { 0, 1, 1, 1 };
            leftHandIKCurve[] = { 0, 1, (4 / 124), 0, (108 / 124), 0, (117 / 124), 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKEnd = true;
        };
        class HLC_GesturereloadSG550_context : HLC_GesturereloadSG550 {
            mask = "handsWeapon_context";
        };
        class HLC_GesturereloadSG553R : Default {
            file = "\hlc_core\animation\gesture\reload_sg553R_standing.rtm";
            looped = 0;
            speed = -(134/30);
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.2;
            headBobMode = 2;
            rightHandIKCurve[] = { 0, 1, 1, 1 };
            leftHandIKCurve[] = { 0, 1, (4 / 124), 0, (108 / 124), 0, (117 / 124), 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKEnd = true;
        };
        class HLC_GesturereloadSG553R_prone : Default {
            file = "hlc_core\animation\gesture\reload_sg553R_prone.rtm";
            speed = -4.133;
            looped = false;
            mask = "handsWeapon";
            headBobStrength = 0.2;
            headBobMode = 2;
            rightHandIKCurve[] = { 0, 1, 1, 1 };
            leftHandIKCurve[] = { 0, 1, (4 / 124), 0, (108 / 124), 0, (117 / 124), 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKEnd = true;
        };
        class HLC_GesturereloadSG553R_context : HLC_GesturereloadSG553R {
            mask = "handsWeapon_context";
        };
        class HLC_GesturereloadSG553RDrum : Default {
            file = "\hlc_core\animation\gesture\reload_sg553Rdrum_standing.rtm";
            looped = 0;
            speed = -(160 / 30);
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.2;
            headBobMode = 2;
            rightHandIKCurve[] = { (113 / 160), 1, (117 / 160), 0, (143 / 160), 0, (147 / 160), 1 };
            leftHandIKCurve[] = { 0, 1, (4 / 160), 0, (108 / 160), 0, (115 / 160), 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKEnd = true;
        };
        class HLC_GesturereloadSG553RDrum_prone : Default {
            file = "hlc_core\animation\gesture\reload_sg553Rdrum_prone.rtm";
            speed = -(160 / 30);
            looped = false;
            mask = "handsWeapon";
            headBobStrength = 0.2;
            headBobMode = 2;
            rightHandIKCurve[] = { (113 / 160), 1, (117 / 160), 0, (143 / 160), 0, (147 / 160), 1 };
            leftHandIKCurve[] = { 0, 1, (4 / 160), 0, (108 / 160), 0, (115 / 160), 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKEnd = true;
        };
        class HLC_GesturereloadSG553RDrum_context : HLC_GesturereloadSG553RDrum {
            mask = "handsWeapon_context";
        };
        class HLC_GestureReloadGL5040 : Default {
            file = "\hlc_core\animation\gesture\reload_gl5040_standing.rtm";
            looped = 0;
            speed = -(107/30);
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.2;
            headBobMode = 2;
            rightHandIKCurve[] = { 0, 1, 1, 1 };
            leftHandIKCurve[] = { 0, 1, (4/107), 0, (90/107), 0, (93/107), 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKEnd = true;
        };
        class HLC_GestureReloadGL5040_prone : Default {
            file = "\hlc_core\animation\gesture\reload_gl5040_prone.rtm";
            speed = -(107/30);
            looped = false;
            mask = "handsWeapon";
            headBobStrength = 0.2;
            headBobMode = 2;
            rightHandIKCurve[] = { 0, 1, 1, 1 };
            leftHandIKCurve[] = { 0, 1, (4 / 107), 0, (90 / 107), 0, (93 / 107), 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            rightHandIKBeg = true;
            rightHandIKEnd = true;
        };
        class HLC_GestureReloadGL5040_context : HLC_GestureReloadGL5040 {
            mask = "handsWeapon_context";
        };
        class NIA_GestureReload416 : Default {
            file = "hlc_core\animation\gesture\reload_ar15_downrange.rtm";
            speed = -(100 / 30);
            looped = false;
            mask = "handsWeapon";
            headBobStrength = 0.1;
            headBobMode = 2;
            rightHandIKCurve[] = { 0, 1, 1, 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = { 0, 1, (6 / 100), 0, (90 / 100), 0, (96 / 100), 1 };
        };
        class NIA_GestureReload416_Prone : Default {
            file = "hlc_core\animation\gesture\reload_ar15_prone_new.rtm";
            looped = 0;
            speed = -(100 / 30);
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.05;
            headBobMode = 2;
            rightHandIKCurve[] = { 0, 1, 1, 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = { 0, 1, (6 / 100), 0, (90 / 100), 0, (96 / 100), 1 };
            rightHandIKEnd = true;
        };
        class NIA_GestureReload416_Context : NIA_GestureReload416 {
            mask = "handsWeapon_context";
        };
        class NIA_GestureReload416_x15 : NIA_GestureReload416
        {
            file = "hlc_core\animation\gesture\reload_ar15_x15_standing.rtm";
        };
        class NIA_GestureReload416_x15_prone : NIA_GestureReload416_Prone
        {
            file = "hlc_core\animation\gesture\reload_ar15_x15_prone.rtm";
        };
        class NIA_GestureReload416_x15_Context : NIA_GestureReload416_x15 {
            mask = "handsWeapon_context";
        };
        class NIA_GestureReload416_WS : Default {
            file = "hlc_core\animation\gesture\reload_ar15_workspace.rtm";
            speed = -(100 / 30);
            looped = false;
            mask = "handsWeapon";
            headBobStrength = 0.3;
            headBobMode = 2;
            rightHandIKCurve[] = { 0, 1, 1, 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = { 0, 1, (6 / 100), 0, (90 / 100), 0, (96 / 100), 1 };
        };
        class NIA_GestureReload416_WS_Prone : Default {
            file = "hlc_core\animation\gesture\reload_ar15_prone_new.rtm";
            looped = 0;
            speed = -(100 / 30);
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.05;
            headBobMode = 2;
            rightHandIKCurve[] = { 0, 1, 1, 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = { 0, 1, (6 / 100), 0, (90 / 100), 0, (96 / 100), 1 };
            rightHandIKEnd = true;
        };
        class NIA_GestureReload416_WS_Context : NIA_GestureReload416_WS {
            mask = "handsWeapon_context";
        };
        class NIA_GestureReload416_BAD : Default {
            file = "hlc_core\animation\gesture\reload_ar15_bad_standing.rtm";
            speed = -(92 / 30);
            looped = false;
            mask = "handsWeapon";
            headBobStrength = 0.3;
            headBobMode = 2;
            rightHandIKCurve[] = { 0, 1, 1, 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = { 0, 1, (6 / 92), 0, (78 / 92), 0, (86 / 92), 1 };
        };
        class NIA_GestureReload416_BAD_Prone : Default {
            file = "hlc_core\animation\gesture\reload_ar15_bad_prone.rtm";
            looped = 0;
            speed = -(92 / 30);
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.05;
            headBobMode = 2;
            rightHandIKCurve[] = { 0, 1, 1, 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = { 0, 1, (6 / 92), 0, (78 / 92), 0, (86 / 92), 1 };
            rightHandIKEnd = true;
        };
        class NIA_GestureReload416_BAD_Context : NIA_GestureReload416_BAD {
            mask = "handsWeapon_context";
        };
        class NIA_GestureReloadAGC : Default {
            file = "hlc_core\animation\gesture\reload_agc_standing.rtm";
            speed = -(125 / 30);
            looped = false;
            mask = "handsWeapon";
            headBobStrength = 0.25;
            headBobMode = 2;
            rightHandIKCurve[] = { 0, 1, 1, 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = { 0, 1, (6 / 125), 0, (118 / 125), 0, (121 / 125), 1 };
        };
        class NIA_GestureReloadAGC_Prone : Default {
            file = "hlc_core\animation\gesture\reload_agc_prone.rtm";
            looped = 0;
            speed = -(125 / 30);
            mask = "handsWeapon";
            // mask="empty";
            headBobStrength = 0.05;
            headBobMode = 2;
            rightHandIKCurve[] = { 0, 1, 1, 1 };
            leftHandIKBeg = true;
            leftHandIKEnd = true;
            leftHandIKCurve[] = { 0, 1, (6 / 125), 0, (118 / 125), 0, (121 / 125), 1 };
            rightHandIKEnd = true;
        };
        class NIA_GestureReloadAGC_Context : NIA_GestureReloadAGC {
            mask = "handsWeapon_context";
        };
        class HLC_GestureReloadACRGL :HLC_GestureReloadGL5040
        {
            file = "hlc_core\animation\gesture\acrgl_reload_standing.rtm";
        };
        class HLC_GestureReloadACRGL_prone : HLC_GestureReloadGL5040_prone
        {
            file = "hlc_core\animation\gesture\acrgl_reload_prone.rtm";
        };
        class HLC_GestureReloadACRGL_context : HLC_GestureReloadACRGL {
            mask = "handsWeapon_context";
        };
    };
};

/*
BALLISTIC DATA PER-BULLET

NOTES -

caliber=(mm/((15*speed)/1000))

mm =     mm st steel at 200m/2.5
Speed  = speed at 200m
*/





class CfgWeapons

{ 
    #include "cfg_acc_muzzle.hpp"
    #include "cfg_acc_sidemount.hpp"
    #include "cfg_acc_scope.hpp"
    #include "cfg_acc_underslot.hpp"



    class HLC_Charm_base : ItemCore
    {
        dlc = "Niarms_Core";
        scope = public;
        author = "Toadie";
        descriptionUse = "$STR_A3_cfgWeapons_use_flashlight0";
        picture = "\hlc_core\tex\UI\gear_dbal_ca.paa";
        model = "hlc_core\mesh\accessories\acc\charms\eurojank.p3d";
        descriptionShort = "$STR_A3_cfgWeapons_acc_flashlight1";
        class ItemInfo : InventoryFlashLightItem_Base_F
        {
            mass = 1;
        };
        inertia = 0.01;
    };
    class HLC_Charm_Eurojank :HLC_Charm_base
    {
        author = "Toadie";
        scope = public;
        displayname = $STR_NIA_Charm_Eurojank;
        model = "hlc_core\mesh\accessories\acc\charms\eurojank.p3d";
        picture = "\hlc_core\tex\UI\cha\gear_eurc_ca.paa";
        descriptionshort = $STR_NIA_Charm_Eurojank_DESC;
    };
    class HLC_Charm_NIArmsbacker :HLC_Charm_base
    {
        author = "Toadie";
        displayname = $STR_NIA_Charm_Backer;
        model = "hlc_core\mesh\accessories\acc\charms\niarms.p3d";
        picture = "\hlc_core\tex\UI\cha\gear_niac_ca.paa";
        descriptionshort = $STR_NIA_Charm_Generic;
    };
    class HLC_Charm_NIArmsbacker_dirty :HLC_Charm_base
    {
        author = "Toadie";
        displayname = $STR_NIA_Charm_BackerDirty;
        model = "hlc_core\mesh\accessories\acc\charms\niarms_dirty.p3d";
        picture = "\hlc_core\tex\UI\cha\gear_niac_ca.paa";
        descriptionshort = $STR_NIA_Charm_Generic;
    };
    class HLC_Charm_Izhmash :HLC_Charm_base
    {
        author = "Toadie";
        displayname = $STR_NIA_Charm_Izhmash;
        model = "hlc_core\mesh\accessories\acc\charms\izhmash.p3d";
        picture = "\hlc_core\tex\UI\cha\gear_izhmash_ca.paa";
        descriptionshort = $STR_NIA_Charm_Izhmash_DESC;
    };
    class HLC_Charm_Herstal :HLC_Charm_base
    {
        author = "Toadie";
        displayname = $STR_NIA_Charm_FN;
        model = "hlc_core\mesh\accessories\acc\charms\FNH.p3d";
        picture = "\hlc_core\tex\UI\cha\gear_herstal_ca.paa";
        descriptionshort = $STR_NIA_Charm_FN_DESC;
    };

    class HLC_Charm_Teethgang :HLC_Charm_base
    {
        displayname = $STR_NIA_Charm_Teethgang;
        model = "hlc_core\mesh\accessories\acc\charms\Beaver_charm.p3d";
        picture = "\hlc_core\tex\UI\cha\gear_beaver_ca.paa";
        descriptionshort = $STR_NIA_Charm_Teethgang_DESC;
    };
    // vanilla compat
    class Rifle_Base_F;
    class mk20_base_F : Rifle_Base_F {
        magazines[] += { __556STANAG_MAGS };
    };
    class SDAR_base_F : Rifle_Base_F {
        magazines[] += { __556STANAG_MAGS };
    };
    class Tavor_base_F : Rifle_Base_F {
        magazines[] += { __556STANAG_MAGS };
    };
    class arifle_SPAR_01_base_F : Rifle_Base_F {
        magazines[] += { __556STANAG_MAGS };
    };
    class arifle_SPAR_02_base_F : Rifle_Base_F {
        magazines[] += { __556STANAG_MAGS };
    };
};

