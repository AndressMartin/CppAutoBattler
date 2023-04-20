#include "BaseStatusEffect.h"
#include "../Character.h"

using namespace StatusEffects;

BaseStatusEffect::BaseStatusEffect(Character& target, std::vector<Types::ProcEvent> events)
: target(target), procEvents(events)
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

bool BaseStatusEffect::ShouldProcOnEvent(Types::ProcEvent event) const
{
    return std::find(procEvents.begin(), procEvents.end(), event) != procEvents.end();
}