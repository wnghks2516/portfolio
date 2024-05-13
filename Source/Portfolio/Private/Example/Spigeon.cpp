// Fill out your copyright notice in the Description page of Project Settings.


#include "Example/Spigeon.h"

USpigeon::USpigeon()
{
	name = TEXT("피죤");
}

void USpigeon::Fly()
{
	UE_LOG(LogTemp, Log, TEXT("%s이 날아오릅니다"), *name);
}
