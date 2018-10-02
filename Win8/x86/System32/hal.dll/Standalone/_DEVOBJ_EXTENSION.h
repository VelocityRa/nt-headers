typedef struct _LIST_ENTRY
{
  /* 0x0000 */ struct _LIST_ENTRY* Flink;
  /* 0x0004 */ struct _LIST_ENTRY* Blink;
} LIST_ENTRY, *PLIST_ENTRY; /* size: 0x0008 */

typedef struct _DEVOBJ_EXTENSION
{
  /* 0x0000 */ short Type;
  /* 0x0002 */ unsigned short Size;
  /* 0x0004 */ struct _DEVICE_OBJECT* DeviceObject;
  /* 0x0008 */ unsigned long PowerFlags;
  /* 0x000c */ struct _DEVICE_OBJECT_POWER_EXTENSION* Dope;
  /* 0x0010 */ unsigned long ExtensionFlags;
  /* 0x0014 */ void* DeviceNode;
  /* 0x0018 */ struct _DEVICE_OBJECT* AttachedTo;
  /* 0x001c */ long StartIoKey;
  /* 0x0020 */ unsigned long StartIoFlags;
  /* 0x0024 */ struct _VPB* Vpb;
  /* 0x0028 */ struct _LIST_ENTRY DependentList;
  /* 0x0030 */ struct _LIST_ENTRY ProviderList;
} DEVOBJ_EXTENSION, *PDEVOBJ_EXTENSION; /* size: 0x0038 */
