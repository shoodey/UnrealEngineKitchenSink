#pragma once

#include "CoreMinimal.h"
#include "Logging/StructuredLog.h"

DECLARE_LOG_CATEGORY_EXTERN(KitchenSink, Log, All);

#define KS_LOG(Verbosity, FormatString, ...) \
	UE_LOGFMT(KitchenSink, Verbosity, FormatString, __VA_ARGS__)
