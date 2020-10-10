#pragma once
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Monster.h"
#include <string>
#include <iostream>
using namespace std;

class MonsterBuilder
{
public:
	string monsterDes[15] = {
		"This bulky feline monster lairs in icy climes. It lures its prey, which includes mundane beasts, monstrous humanoids, other predators, and small creatures. It attacks with a tail striker, venom and debilitating effects. Legend holds that they were created by an experiment gone wrong.",
		"This towering, insect-like, ethereal monster can be found in marshes. It attacks with spikes, noxious fumes and cold. It fears a certain metal.",
		"This medium-sized, unnatural, bird-like beast makes its home in deserts. It tracks its prey, which includes monstrous humanoids and mundane beasts. It attacks with spines, psionics and creeping darkness. They travel in tribes of 5-16. Some legends say that they have a hidden, primitive civilization.",
		"This towering chimeric beast lives in deep lakes. It attacks with spines, a hypnotic song and creeping darkness. Folktales say that various body parts are much sought after as ritual components.",
		"This large fiendish monster dwells in underground caverns. It stalks its prey, which includes medium-sized creatures, small creatures, and other predators. It attacks with dizzying blows, electricity, projectile weapons and necrotic energy. They live in packs of 1-5.",
		"This small insect-like beast dwells in coastal areas. It attacks with a tail striker, an eldritch aura and thrown weapons. It dislikes bright light. They lair in groups of 3-9. According to myth, they cooperate with other monsters.",
		"This dog-sized chimeric beast makes its home in mountains. It lies in wait for its prey, which includes other predators, large creatures, magical beasts, and mundane beasts. It attacks with spikes, acid, projectile weapons and obscuring fog. It is weak against ash. Rumor has it that they do most of their hunting at twilight.",
		"This runty reptilian creature dwells in mountains. It lies in wait for its prey, which includes other monsters of the same type, humans, and mundane beasts. It attacks with slashing claws, debilitating effects and psionics. They lair in flocks of 3-10. According to folktales, various body parts are much sought after as ritual components.",
		"This bear-sized bird-like beast lives in city sewers. It leaps upon its prey, which includes other predators, medium-sized creatures, other monsters of the same type, and monstrous humanoids. It attacks with piercing claws, obscuring fog and necrotic energy.",
		"This human-sized snake-like beast lairs in swamps. It lies in wait for its prey, which includes other predators, mundane beasts, large creatures, and other monsters of the same type. It attacks with rapid blows, toxic bites, fire and necrotic energy. It dislikes certain symbols. According to myth, they keep hordes of treasure.",
		"This hulking oozing monster can be found in deserts. It attacks with crushing blows and toxic bites. It dislikes certain herbs. They hunt alone. Rumor has it that they keep trophies from slain prey.",
		"This horse-sized, phantasmal, canine monster can be found in city sewers. It stalks its prey, which includes humans, other predators, and monstrous humanoids. It attacks with piercing claws, obscuring fog and entangling webs.",
		"This horse-sized, mongrel, bird-like monster lives in untamed grasslands. It lies in wait for its prey, which includes large creatures and mundane beasts. It attacks with a tail striker and a hypnotic gaze.",
		"This towering, fiendish, phantasmal beast lives in deep forests. It stalks its prey, which includes other monsters of the same type and mundane beasts. It attacks with piercing claws, choking smoke and grasping tentacles. It is difficult to harm without bright light. They hunt in bands of 5-12.",
		"This medium-sized mongrel beast lives in wooded areas. It lures its prey, which includes other predators, mundane beasts, medium-sized creatures, and other monsters of the same type. It attacks with crushing blows, projectile weapons and sound. They live in tribes of 2-5."
	};

	Monster buildMonster() {
		Monster monster(rand() % 5, rand() % 5, rand() % 5, monsterDes[rand() % 15]);
		return monster;
	}
};

