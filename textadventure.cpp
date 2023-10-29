#include <iostream>
//videogame11!11!!!
float page;
using namespace std;
bool keycard;
bool traps_disabled;
void respawn() {
    printf("\nYou died! Back to the beginning: You see doors <forward>, <left>, and <right>.");
    page = 1;
    keycard = false;
    traps_disabled = false;
}
int main() {
    page = 1;
    printf("It's 2042, the whole world is a dictatorship of Lucas the Little, the son of Charlemagne the Little.\nYou, as a respectable officer, must go back to 1980 to assassinate the Emperor, Charlemagne the Little, before the world becomes a dictatorship.\nYou see doors <forward>, <left>, and <right>.");
    while (true) {
        string x;
        cin >> x;
        if (x == "left" && page == 1) {
            printf("You open the door and enter Shrek's swamp!.\nYou have a little chat, while he dissects you piece by piece.");
            respawn();
        }
        if (x == "right" && page == 1) {
            if (!keycard) {
                printf("You fall into what seems like an infinitely deep pit.\nEventually, you see the ground with many beautiful lights.\nYou are pierced by spears.");
                respawn();
            }
            else if (page == 1) {
                page = 3;
                printf("A floating bridge forms in front of you. You walk on the bridge.\nThe bridge disappears beneath your feet.\nThe next bridge you see is closed. Do you <swim> across or <search> for another way out?");
            }
        }
        if (x == "forward" && !traps_disabled && page == 1) {
            page = 2;
            printf("You see a <key> you can pick up, or you can activate a <elevation>.");
        }
        if (x == "swim" && page == 3) {
            page = 5;
            printf("You are pulled down!\nYou swim through a hole.\nNow you are in a dungeon.\nYou see an old <door> and skulls on the ground. You also consider <swimming> back.");
        }
        if (x == "swimming" && page == 5) {
            printf("In a fierce battle with the waves, you have swum out of the dungeon. You see a donkey running towards you.\nYou have Equinophobia (fear of donkeys), so you dive back into the water. You are back in the dungeon. Great!\n");
            x = "door";
        }
        if (x == "door" && page == 5) {
            page = 6;
            printf("You try to open the door and notice a lever. You use the lever, and the door closes behind you. You are trapped!\nYou can go <up> or <down> via the stairs.");
        }
        if (x == "down" && page == 6) {
            printf("You go down the stairs and see a sword and shield hanging on the wall, with runes on the sword. You also see a large, old Viking. He helps you out of the dungeon and bids you farewell.\n");
            page = 100;
            printf("end up in a large Viking fortress. Inside, you see Vikings fighting each other. The bodies of the defeated do not go to Valhalla but bleed on the ground. You see a <hatch> leading down and a <door> to the left.");
        }
        if (x == "up" && page == 6) {
            printf("You go up the stairs and open a door. You meet a minion!\nHe knocks you unconscious and hangs you up.\nHe cuts you open and eats your entrails.");
            respawn();
        }
        if (x == "search" && page == 3) {
            page = 100;
            printf("You walk over another bridge, which leads to a dead end. You kick in the door and find yourself in a large Viking fortress. Inside, you see Vikings fighting each other. The bodies of the defeated do not go to Valhalla but bleed on the ground. You see a <hatch> leading down and a <door> to the left.");
        }
        if (x == "hatch" && page == 100) {
            page = 101;
            printf("You open a hatch, but a Viking attacks you from behind! Do you <dive> away or <jump> over him?");
        }
        if (x == "jump" && page == 101) {
            printf("You try to jump over him\nYou hit his head, he stabs you in the stomach, and you bleed to death.");
            respawn();
        }
        if (x == "dive" && page == 101) {
            page = 150;
            printf("You dive under him and stab him with your sword.\nJust like all the other defeated, this corpse also doesn't go to Valhalla.\nUnder the hatch is a meeting with Charlemagne the Little, with many guards.\nDo you go for <Charlemagne> the Little, or for the <Vikings>?");
        }
        if (x == "door" && page == 100) {
            printf("You open the door and run down the stairs.\nYou have reached the room of Charlemagne the Little, their leader.\nCharlemagne is surrounded by many Vikings. Do you go for <Charlemagne> or for the <Vikings>?");
            page = 150;
        }
        if (x == "key" && page == 2) {
            if (traps_disabled) {
                printf("You have picked up the key with the arrow next to it.\nYou go back to the first room. The door you came out of is closed. You see doors <left> and <right>.");
                page = 1;
                keycard = true;
            }
            else if (page == 2) {
                printf("You have picked up the key, but it was a trap. An arrow impales your head.");
                respawn();
            }
        }
        if (x == "elevation" && !traps_disabled && page == 2) {
            traps_disabled = true;
            printf("You see an elevation on the floor, which you stand on. Many traps have been triggered.\nThere is a <key> that you can pick up.");
        }
        if (x == "charlemagne" && page == 150) {
            printf("You are too overconfident...\nThe Vikings of Charlemagne grab you by the throat and carry out a public execution! Everyone can take a piece!");
            respawn();
        }
        if (x == "vikings" && page == 150) {
            printf("Charlemagne the Little quickly runs away, leaving you with the Vikings who beat you to death one by one. You pick up a bow from a Viking and use your arrow.\nA Viking runs after you. Do you hit him in the <throat> or try to hit him on the <temple>?");
            page = 151;
    }
    if (x == "temple" && page == 151) {
        printf("You hit the Viking on his temple, and he faints.\nYou kill him and take a helmet from another Viking.\nHe tries to hit you.\nDo you defend yourself in your <stomach> or at your <head>.\n");
        page = 152;
    }
    if (x == "throat" && page == 151) {
        printf("He blocks your blow and strikes you once\nHe pricks your eyes before feasting on your entrails.");
        respawn();
    }
    if (x == "stomach" && page == 152) {
        printf("\n\nYou block his blow, cut off his arms, and stab him.\nHe's dead.\nCharlemagne the Little is now sitting alone on his bed crying.\n\"Don't hurt me!\"\n You're a nice guy, so you finish him off quickly.\nCharlemagne the Little is murdered, and therefore Lucas the Little is gone as well!\nA portal opens back to your home, where you are received as a hero!\nThe rest of your life is spent with a big stomach and a nice pension.");
        page=-1;
    }
    if (x == "head" && page == 152) {
        printf("He pricks you in the stomach, and you bleed to death.");
        respawn();
    }
    if (x == "x") {
        printf("%.0f", page);
    }
}
}
