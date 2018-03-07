//
// Created by Hans-Wilhelm Warlo on 07/03/2018.
//

#pragma once

#include <algorithm>
#include <atomic>
#include <chrono>
#include <deque>
#include "port/port.h"
#include "rocksdb/env.h"
#include "rocksdb/rate_limiter.h"
#include "util/mutexlock.h"
#include "util/random.h"
#include "util/rate_limiter.h"

namespace rocksdb {

class WriteLoadTuner : public GenericRateLimiter {
public:
    WriteLoadTuner(int64_t rate_bytes_per_sec,
                   int64_t refill_period_us,
                   int32_t fairness, RateLimiter::Mode mode,
                   Env* env, bool auto_tuned);

    virtual ~WriteLoadTuner();
};
} // namespace rocksdb
