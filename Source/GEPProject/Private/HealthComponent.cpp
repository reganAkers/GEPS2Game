// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values
AHealthComponent::AHealthComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_MaxHealth = 100.0f;
	m_MaxShield = 100.0f;
	m_CanRegenShield = true;
	m_ShieldRecoverRate = 10.0f;
	m_ShieldRecoverDelay = 2.0f;
	

}

// Called when the game starts or when spawned
void AHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &AHealthComponent::DamageTaken);
	m_CurrentHealth = m_MaxHealth;
	m_CurrentShield = m_MaxShield;
}

void AHealthComponent::DamageTaken(AActor* damagedActor, float damage, const UDamageType* damageType,
	AController* instigator, AActor* causer)
{
	float leftOverDamage = FMath::Max(damage - m_CurrentShield, 0.0f); // Checks if there is more damage after breaking shield
	m_CurrentShield = FMath::Max(m_CurrentShield - damage, 0.0f);
	m_ShieldRecoverDelayTimer = m_ShieldRecoverDelay;

	if (leftOverDamage > 0.0f) { m_CurrentHealth = FMath::Max(m_CurrentHealth - leftOverDamage, 0.0f); } // Applies the rest of the damage to the health

	if (m_CurrentHealth <= 0.0f) { onComponentDead.Broadcast(instigator); }
}

// Called every frame
void AHealthComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_CurrentShield < m_MaxShield && m_CanRegenShield)
	{
		if (m_ShieldRecoverDelayTimer > 0.0f)
		{
			m_ShieldRecoverDelayTimer -= DeltaTime;
		}
		else
		{
			m_CurrentShield = FMath::Min(m_MaxShield, m_CurrentShield + (m_ShieldRecoverRate * DeltaTime));
		}
		
	}
}

