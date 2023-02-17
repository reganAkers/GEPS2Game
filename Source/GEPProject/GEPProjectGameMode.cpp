// Copyright Epic Games, Inc. All Rights Reserved.

#include "GEPProjectGameMode.h"
#include "GEPProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGEPProjectGameMode::AGEPProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
