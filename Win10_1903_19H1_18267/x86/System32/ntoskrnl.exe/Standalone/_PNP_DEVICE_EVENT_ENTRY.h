typedef struct _LIST_ENTRY
{
  /* 0x0000 */ struct _LIST_ENTRY* Flink;
  /* 0x0004 */ struct _LIST_ENTRY* Blink;
} LIST_ENTRY, *PLIST_ENTRY; /* size: 0x0008 */

typedef struct _GUID
{
  /* 0x0000 */ unsigned long Data1;
  /* 0x0004 */ unsigned short Data2;
  /* 0x0006 */ unsigned short Data3;
  /* 0x0008 */ unsigned char Data4[8];
} GUID, *PGUID; /* size: 0x0010 */

typedef enum _PLUGPLAY_EVENT_CATEGORY
{
  HardwareProfileChangeEvent = 0,
  TargetDeviceChangeEvent = 1,
  DeviceClassChangeEvent = 2,
  CustomDeviceEvent = 3,
  DeviceInstallEvent = 4,
  DeviceArrivalEvent = 5,
  VetoEvent = 6,
  BlockedDriverEvent = 7,
  InvalidIDEvent = 8,
  DevicePropertyChangeEvent = 9,
  DeviceInstanceRemovalEvent = 10,
  DeviceInstanceStartedEvent = 11,
  MaxPlugEventCategory = 12,
} PLUGPLAY_EVENT_CATEGORY, *PPLUGPLAY_EVENT_CATEGORY;

typedef enum _PNP_VETO_TYPE
{
  PNP_VetoTypeUnknown = 0,
  PNP_VetoLegacyDevice = 1,
  PNP_VetoPendingClose = 2,
  PNP_VetoWindowsApp = 3,
  PNP_VetoWindowsService = 4,
  PNP_VetoOutstandingOpen = 5,
  PNP_VetoDevice = 6,
  PNP_VetoDriver = 7,
  PNP_VetoIllegalDeviceRequest = 8,
  PNP_VetoInsufficientPower = 9,
  PNP_VetoNonDisableable = 10,
  PNP_VetoLegacyDriver = 11,
  PNP_VetoInsufficientRights = 12,
  PNP_VetoAlreadyRemoved = 13,
} PNP_VETO_TYPE, *PPNP_VETO_TYPE;

typedef struct _PLUGPLAY_EVENT_BLOCK
{
  /* 0x0000 */ struct _GUID EventGuid;
  /* 0x0010 */ enum _PLUGPLAY_EVENT_CATEGORY EventCategory;
  /* 0x0014 */ unsigned long* Result;
  /* 0x0018 */ unsigned long Flags;
  /* 0x001c */ unsigned long TotalSize;
  /* 0x0020 */ void* DeviceObject;
  union // _TAG_UNNAMED_128
  {
    union
    {
      struct // _TAG_UNNAMED_129
      {
        /* 0x0024 */ struct _GUID ClassGuid;
        /* 0x0034 */ wchar_t SymbolicLinkName[1];
        /* 0x0036 */ char __PADDING__[2];
      } /* size: 0x0014 */ DeviceClass;
      struct // _TAG_UNNAMED_130
      {
        /* 0x0024 */ wchar_t DeviceId[1];
      } /* size: 0x0002 */ TargetDevice;
      struct // _TAG_UNNAMED_130
      {
        /* 0x0024 */ wchar_t DeviceId[1];
      } /* size: 0x0002 */ InstallDevice;
      struct // _TAG_UNNAMED_131
      {
        /* 0x0024 */ void* NotificationStructure;
        /* 0x0028 */ wchar_t DeviceId[1];
        /* 0x002a */ char __PADDING__[2];
      } /* size: 0x0008 */ CustomNotification;
      struct // _TAG_UNNAMED_132
      {
        /* 0x0024 */ void* Notification;
      } /* size: 0x0004 */ ProfileNotification;
      struct // _TAG_UNNAMED_133
      {
        /* 0x0024 */ unsigned long NotificationCode;
        /* 0x0028 */ unsigned long NotificationData;
      } /* size: 0x0008 */ PowerNotification;
      struct // _TAG_UNNAMED_134
      {
        /* 0x0024 */ enum _PNP_VETO_TYPE VetoType;
        /* 0x0028 */ wchar_t DeviceIdVetoNameBuffer[1];
        /* 0x002a */ char __PADDING__[2];
      } /* size: 0x0008 */ VetoNotification;
      struct // _TAG_UNNAMED_135
      {
        /* 0x0024 */ struct _GUID BlockedDriverGuid;
      } /* size: 0x0010 */ BlockedDriverNotification;
      struct // _TAG_UNNAMED_136
      {
        /* 0x0024 */ wchar_t ParentId[1];
      } /* size: 0x0002 */ InvalidIDNotification;
      struct // _TAG_UNNAMED_137
      {
        /* 0x0024 */ struct _GUID PowerSettingGuid;
        /* 0x0034 */ unsigned long Flags;
        /* 0x0038 */ unsigned long SessionId;
        /* 0x003c */ unsigned long DataLength;
        /* 0x0040 */ unsigned char Data[1];
        /* 0x0041 */ char __PADDING__[3];
      } /* size: 0x0020 */ PowerSettingNotification;
      struct // _TAG_UNNAMED_130
      {
        /* 0x0024 */ wchar_t DeviceId[1];
      } /* size: 0x0002 */ PropertyChangeNotification;
      struct // _TAG_UNNAMED_130
      {
        /* 0x0024 */ wchar_t DeviceId[1];
      } /* size: 0x0002 */ DeviceInstanceNotification;
    }; /* size: 0x0020 */
  } /* size: 0x0020 */ u;
} PLUGPLAY_EVENT_BLOCK, *PPLUGPLAY_EVENT_BLOCK; /* size: 0x0044 */

typedef struct _PNP_DEVICE_EVENT_ENTRY
{
  /* 0x0000 */ struct _LIST_ENTRY ListEntry;
  /* 0x0008 */ unsigned long Argument;
  /* 0x000c */ long ArgumentStatus;
  /* 0x0010 */ struct _KEVENT* CallerEvent;
  /* 0x0014 */ void* Callback /* function */;
  /* 0x0018 */ void* Context;
  /* 0x001c */ enum _PNP_VETO_TYPE* VetoType;
  /* 0x0020 */ struct _UNICODE_STRING* VetoName;
  /* 0x0024 */ unsigned long RefCount;
  /* 0x0028 */ unsigned long Lock;
  /* 0x002c */ unsigned char Cancel;
  /* 0x0030 */ struct _PNP_DEVICE_EVENT_ENTRY* Parent;
  /* 0x0034 */ struct _GUID ActivityId;
  /* 0x0044 */ struct _PNP_WATCHDOG* Watchdog;
  /* 0x0048 */ struct _PLUGPLAY_EVENT_BLOCK Data;
} PNP_DEVICE_EVENT_ENTRY, *PPNP_DEVICE_EVENT_ENTRY; /* size: 0x008c */

