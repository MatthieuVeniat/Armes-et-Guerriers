#include<iostream>

#include"../ChaineCar/ChaineCar.h"
#include"Arme.h"
#include"ArmesSpecialisees.h"

ArmeCorpsACorps::ArmeCorpsACorps(const char* name, int b): Arme(name,b){}

ArmeDistance::ArmeDistance(const char* name, int b) : Arme(name, b) {}

ArmeMagique::ArmeMagique(const char* name, int b) : Arme(name, b) {}

ArmeDeBase::ArmeDeBase(const char* name, int b) : Arme(name, b) {}