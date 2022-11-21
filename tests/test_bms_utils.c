#include "munit.h"
#include "bms_utils.h"

static MunitResult
test_create_timestamp(const MunitParameter params[], void* data) {
  // Silence compiler warnings
  (void) params;
  (void) data;

  time_t epoch = create_timestamp(1970, 0, 1, 0, 0, 0, 0);

  munit_assert(epoch == 0);
}