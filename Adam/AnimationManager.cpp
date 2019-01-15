#include "AnimationManager.h"


AnimationManager::AnimationManager(const std::string & s)
{
	std::ifstream in(s, std::ios::in | std::ios::binary);
	if (!in) {
		std::cout << "Couldn't open " << s << std::endl;
	}
	std::string object, action, path = "";
	size_t size_x, size_y;
	while (in >> object >> action >> path >> size_x >> size_y) {
		sf::Texture t;
		Animation a;
		Collision::CreateTextureAndBitmask(t, "assets/" + path);
		auto pos = animations.find(object);
		if (pos != animations.end()) {
			auto pos2 = pos->second.find(action);
			if (pos2 != pos->second.end()) {
				a = pos2->second;
			}
			else {
				pos->second[action] = a;
			}	
		}else{
			animations[object][action] = a;
		}
		animations[object][action].addFrame(t);
	}
}

void AnimationManager::print()
{
	for (auto elem : animations)
	{
		for (auto m : elem.second) {
			std::cout << elem.first << " " << m.first << " " << m.second.textures.size() << std::endl;
		}
		
	}
}

AnimationManager::~AnimationManager()
{
}
