#include "BaseStatusEffect.h"
#include "../Character.h"

using namespace StatusEffects;

BaseStatusEffect::BaseStatusEffect(Character& target)
: target(target)
{
}
void BaseStatusEffect::Proc()
{
}

void BaseStatusEffect::Inflict(Character& target)
{
    std::unique_ptr<BaseStatusEffect> newEffect = Clone(target);
    target.GetInflictedWithStatus(std::move(newEffect));
}