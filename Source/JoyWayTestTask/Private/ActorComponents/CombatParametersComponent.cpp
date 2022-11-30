// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorComponents/CombatParametersComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
UCombatParametersComponent::UCombatParametersComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UCombatParametersComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UCombatParametersComponent::GetHealthStats(float &CurrenHP, float &MaxHP) const
{
	MaxHP = CombatParameters.MaxHealth;
	CurrenHP = CombatParameters.CurrentHealth;
}

void UCombatParametersComponent::TakeDamage(float DamageSize, AActor* DamageSource)
{
	CombatParameters.CurrentHealth = UKismetMathLibrary::Clamp((CombatParameters.CurrentHealth - DamageSize), 0, CombatParameters.MaxHealth);
	NotifyHealthChanged(CombatParameters.CurrentHealth, CombatParameters.MaxHealth);
	NotifyTakeDamage(DamageSize, DamageSource);
}

void UCombatParametersComponent::HealthRecover(float RecoverableHealth)
{
	CombatParameters.CurrentHealth = UKismetMathLibrary::Clamp((CombatParameters.CurrentHealth + RecoverableHealth), 0, CombatParameters.MaxHealth);
	NotifyHealthChanged(CombatParameters.CurrentHealth, CombatParameters.MaxHealth);
}

void UCombatParametersComponent::NotifyHealthChanged(float CurrentHP, float MaxHP)
{
	OnHealthChangedNative.Broadcast(CurrentHP, MaxHP);
	OnHealthChanged.Broadcast(CurrentHP, MaxHP);

	CallHealthChanged(CurrentHP, MaxHP);
}

void UCombatParametersComponent::NotifyTakeDamage(float DamageSize, AActor* DamageSource)
{
	OnTakeDamageNative.Broadcast(DamageSize, DamageSource);
	OnTakeDamage.Broadcast(DamageSize, DamageSource);

	CallTakeDamage(DamageSize, DamageSource);
}