typedef struct _ARBITER_TEST_ALLOCATION_PARAMETERS
{
  /* 0x0000 */ struct _LIST_ENTRY* ArbitrationList;
  /* 0x0004 */ unsigned long AllocateFromCount;
  /* 0x0008 */ struct _CM_PARTIAL_RESOURCE_DESCRIPTOR* AllocateFrom;
} ARBITER_TEST_ALLOCATION_PARAMETERS, *PARBITER_TEST_ALLOCATION_PARAMETERS; /* size: 0x000c */

typedef struct _ARBITER_RETEST_ALLOCATION_PARAMETERS
{
  /* 0x0000 */ struct _LIST_ENTRY* ArbitrationList;
  /* 0x0004 */ unsigned long AllocateFromCount;
  /* 0x0008 */ struct _CM_PARTIAL_RESOURCE_DESCRIPTOR* AllocateFrom;
} ARBITER_RETEST_ALLOCATION_PARAMETERS, *PARBITER_RETEST_ALLOCATION_PARAMETERS; /* size: 0x000c */

typedef struct _ARBITER_BOOT_ALLOCATION_PARAMETERS
{
  /* 0x0000 */ struct _LIST_ENTRY* ArbitrationList;
} ARBITER_BOOT_ALLOCATION_PARAMETERS, *PARBITER_BOOT_ALLOCATION_PARAMETERS; /* size: 0x0004 */

typedef struct _ARBITER_QUERY_ALLOCATED_RESOURCES_PARAMETERS
{
  /* 0x0000 */ struct _CM_PARTIAL_RESOURCE_LIST** AllocatedResources;
} ARBITER_QUERY_ALLOCATED_RESOURCES_PARAMETERS, *PARBITER_QUERY_ALLOCATED_RESOURCES_PARAMETERS; /* size: 0x0004 */

typedef struct _ARBITER_QUERY_CONFLICT_PARAMETERS
{
  /* 0x0000 */ struct _DEVICE_OBJECT* PhysicalDeviceObject;
  /* 0x0004 */ struct _IO_RESOURCE_DESCRIPTOR* ConflictingResource;
  /* 0x0008 */ unsigned long* ConflictCount;
  /* 0x000c */ struct _ARBITER_CONFLICT_INFO** Conflicts;
} ARBITER_QUERY_CONFLICT_PARAMETERS, *PARBITER_QUERY_CONFLICT_PARAMETERS; /* size: 0x0010 */

typedef struct _ARBITER_QUERY_ARBITRATE_PARAMETERS
{
  /* 0x0000 */ struct _LIST_ENTRY* ArbitrationList;
} ARBITER_QUERY_ARBITRATE_PARAMETERS, *PARBITER_QUERY_ARBITRATE_PARAMETERS; /* size: 0x0004 */

typedef struct _ARBITER_ADD_RESERVED_PARAMETERS
{
  /* 0x0000 */ struct _DEVICE_OBJECT* ReserveDevice;
} ARBITER_ADD_RESERVED_PARAMETERS, *PARBITER_ADD_RESERVED_PARAMETERS; /* size: 0x0004 */

typedef struct _ARBITER_PARAMETERS
{
  union // _TAG_UNNAMED_241
  {
    union
    {
      /* 0x0000 */ struct _ARBITER_TEST_ALLOCATION_PARAMETERS TestAllocation;
      /* 0x0000 */ struct _ARBITER_RETEST_ALLOCATION_PARAMETERS RetestAllocation;
      /* 0x0000 */ struct _ARBITER_BOOT_ALLOCATION_PARAMETERS BootAllocation;
      /* 0x0000 */ struct _ARBITER_QUERY_ALLOCATED_RESOURCES_PARAMETERS QueryAllocatedResources;
      /* 0x0000 */ struct _ARBITER_QUERY_CONFLICT_PARAMETERS QueryConflict;
      /* 0x0000 */ struct _ARBITER_QUERY_ARBITRATE_PARAMETERS QueryArbitrate;
      /* 0x0000 */ struct _ARBITER_ADD_RESERVED_PARAMETERS AddReserved;
    }; /* size: 0x0010 */
  } /* size: 0x0010 */ Parameters;
} ARBITER_PARAMETERS, *PARBITER_PARAMETERS; /* size: 0x0010 */

