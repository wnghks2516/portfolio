﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Example/Spigeon.h"

USpigeon::USpigeon()
{
	Name = TEXT("피죤");
	ID = 0;
}

void USpigeon::Fly()
{
	UE_LOG(LogTemp, Log, TEXT("%s이 날아오릅니다"), *Name);
}

void USpigeon::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	Ar << Name;
	Ar << ID;
}

