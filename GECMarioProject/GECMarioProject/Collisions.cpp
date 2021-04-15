#include "Collisions.h"
#include "Character.h"

// initialise instance to nullptr
Collisions* Collisions::m_instance = nullptr;

Collisions::Collisions()
{

}

Collisions::~Collisions()
{
	m_instance = nullptr;
}

Collisions* Collisions::Instance()
{
	if (!m_instance)
	{
		m_instance = new Collisions;
	}
	return m_instance;
}

bool Collisions::Circle(Character* character1, Character* character2)
{
	Vector2D vec = Vector2D((character1->GetPosition().x - character2->GetPosition().x),
		character1->GetPosition().y - character2->GetPosition().y); // calculate vector that seperates two objects

	// calculate legnth of the vector
	double distance = sqrt((vec.x * vec.x) + (vec.y * vec.y));

	// get collision radius of each character and accululate them
	double combined_distance = (character1->GetCollisionRadius() + character2->GetCollisionRadius());

	// check whether the distance is showerer than accumulated collision radii
	return distance < combined_distance;
}

bool Collisions::Box(Rect2D rect1, Rect2D rect2)
{
	if (rect1.x + (rect1.width / 2) > rect2.x &&
		rect1.x + (rect1.width / 2) < rect2.x + rect2.width &&
		rect1.y + (rect1.height / 2) > rect2.y &&
		rect1.y + (rect1.height / 2) < rect2.y + rect2.height)
	{
		return true;
	}
	return false;
}