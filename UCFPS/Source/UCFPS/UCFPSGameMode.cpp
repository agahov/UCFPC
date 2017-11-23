// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "UCFPSGameMode.h"
#include "UCFPSHUD.h"
#include "UCFPSCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUCFPSGameMode::AUCFPSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AUCFPSHUD::StaticClass();
}
