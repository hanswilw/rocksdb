//
// Created by Hans-Wilhelm Warlo on 07/03/2018.
//

#include "util/rate_limiter.h"
#include "monitoring/statistics.h"
#include "port/port.h"
#include "rocksdb/env.h"
#include "util/aligned_buffer.h"
#include "util/sync_point.h"
#include "write_load_tuner.h"

namespace rocksdb {

WriteLoadTuner::WriteLoadTuner(int64_t rate_bytes_per_sec, int64_t refill_period_us, int32_t fairness,
                               RateLimiter::Mode mode, Env *env, bool auto_tuned)
        : GenericRateLimiter(rate_bytes_per_sec, refill_period_us, fairness, mode, env, auto_tuned) {

}

GenericRateLimiter* NewWriteLoadTuner(
        int64_t rate_bytes_per_sec, int64_t refill_period_us /* = 100 * 1000 */,
        int32_t fairness /* = 10 */,
        RateLimiter::Mode mode /* = RateLimiter::Mode::kWritesOnly */,
        bool auto_tuned /* = false */) {
    assert(rate_bytes_per_sec > 0);
    assert(refill_period_us > 0);
    assert(fairness > 0);
    return new WriteLoadTuner(rate_bytes_per_sec, refill_period_us, fairness,
                              mode, Env::Default(), auto_tuned);
}


}