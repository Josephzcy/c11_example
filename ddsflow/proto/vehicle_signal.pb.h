// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: vehicle_signal.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_vehicle_5fsignal_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_vehicle_5fsignal_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3013000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3013000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/map.h>  // IWYU pragma: export
#include <google/protobuf/map_entry.h>
#include <google/protobuf/map_field_inl.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include <google/protobuf/any.pb.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_vehicle_5fsignal_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_vehicle_5fsignal_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_vehicle_5fsignal_2eproto;
namespace minieye {
class CommandSignal;
class CommandSignalDefaultTypeInternal;
extern CommandSignalDefaultTypeInternal _CommandSignal_default_instance_;
class VehicleSignal;
class VehicleSignalDefaultTypeInternal;
extern VehicleSignalDefaultTypeInternal _VehicleSignal_default_instance_;
class VehicleSignal_SignalsEntry_DoNotUse;
class VehicleSignal_SignalsEntry_DoNotUseDefaultTypeInternal;
extern VehicleSignal_SignalsEntry_DoNotUseDefaultTypeInternal _VehicleSignal_SignalsEntry_DoNotUse_default_instance_;
}  // namespace minieye
PROTOBUF_NAMESPACE_OPEN
template<> ::minieye::CommandSignal* Arena::CreateMaybeMessage<::minieye::CommandSignal>(Arena*);
template<> ::minieye::VehicleSignal* Arena::CreateMaybeMessage<::minieye::VehicleSignal>(Arena*);
template<> ::minieye::VehicleSignal_SignalsEntry_DoNotUse* Arena::CreateMaybeMessage<::minieye::VehicleSignal_SignalsEntry_DoNotUse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace minieye {

enum VehicleSignal_SignalType : int {
  VehicleSignal_SignalType_kInvalid = 0,
  VehicleSignal_SignalType_kSteeringWheelAngle = 1,
  VehicleSignal_SignalType_kSteeringWheelDirect = 2,
  VehicleSignal_SignalType_kLenkmoment = 3,
  VehicleSignal_SignalType_kLenkmomentQbit = 4,
  VehicleSignal_SignalType_kWheelSpeedFl = 5,
  VehicleSignal_SignalType_kWheelSpeedFlDirect = 6,
  VehicleSignal_SignalType_kWheelSpeedFr = 7,
  VehicleSignal_SignalType_kWheelSpeedFrDirect = 8,
  VehicleSignal_SignalType_kWheelSpeedRl = 9,
  VehicleSignal_SignalType_kWheelSpeedRlDirect = 10,
  VehicleSignal_SignalType_kWheelSpeedRr = 11,
  VehicleSignal_SignalType_kWheelSpeedRrDirect = 12,
  VehicleSignal_SignalType_kTargetGear = 13,
  VehicleSignal_SignalType_kShortDisRadarFl = 14,
  VehicleSignal_SignalType_kShortDisRadarFlm = 15,
  VehicleSignal_SignalType_kShortDisRadarFrm = 16,
  VehicleSignal_SignalType_kShortDisRadarFr = 17,
  VehicleSignal_SignalType_kShortDisRadarBl = 18,
  VehicleSignal_SignalType_kShortDisRadarBlm = 19,
  VehicleSignal_SignalType_kShortDisRadarBrm = 20,
  VehicleSignal_SignalType_kShortDisRadarBr = 21,
  VehicleSignal_SignalType_kLongDisRadarFl = 22,
  VehicleSignal_SignalType_kLongDisRadarFr = 23,
  VehicleSignal_SignalType_kLongDisRadarBl = 24,
  VehicleSignal_SignalType_kLongDisRadarBr = 25,
  VehicleSignal_SignalType_kWheelSpeed2Fl = 26,
  VehicleSignal_SignalType_kWheelSpeed2Fr = 27,
  VehicleSignal_SignalType_kWheelSpeed2Rl = 28,
  VehicleSignal_SignalType_kWheelSpeed2Rr = 29,
  VehicleSignal_SignalType_kGierrate = 30,
  VehicleSignal_SignalType_kGierrateDirect = 31,
  VehicleSignal_SignalType_kLongitudinalAc = 32,
  VehicleSignal_SignalType_kLaterallyAc = 33,
  VehicleSignal_SignalType_kPlaStatus = 34,
  VehicleSignal_SignalType_kPlaResp = 35,
  VehicleSignal_SignalType_kCanSpeed = 36,
  VehicleSignal_SignalType_VehicleSignal_SignalType_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  VehicleSignal_SignalType_VehicleSignal_SignalType_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool VehicleSignal_SignalType_IsValid(int value);
constexpr VehicleSignal_SignalType VehicleSignal_SignalType_SignalType_MIN = VehicleSignal_SignalType_kInvalid;
constexpr VehicleSignal_SignalType VehicleSignal_SignalType_SignalType_MAX = VehicleSignal_SignalType_kCanSpeed;
constexpr int VehicleSignal_SignalType_SignalType_ARRAYSIZE = VehicleSignal_SignalType_SignalType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* VehicleSignal_SignalType_descriptor();
template<typename T>
inline const std::string& VehicleSignal_SignalType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, VehicleSignal_SignalType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function VehicleSignal_SignalType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    VehicleSignal_SignalType_descriptor(), enum_t_value);
}
inline bool VehicleSignal_SignalType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, VehicleSignal_SignalType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<VehicleSignal_SignalType>(
    VehicleSignal_SignalType_descriptor(), name, value);
}
enum CommandSignal_SignalType : int {
  CommandSignal_SignalType_kUnknown = 0,
  CommandSignal_SignalType_CommandSignal_SignalType_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  CommandSignal_SignalType_CommandSignal_SignalType_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool CommandSignal_SignalType_IsValid(int value);
constexpr CommandSignal_SignalType CommandSignal_SignalType_SignalType_MIN = CommandSignal_SignalType_kUnknown;
constexpr CommandSignal_SignalType CommandSignal_SignalType_SignalType_MAX = CommandSignal_SignalType_kUnknown;
constexpr int CommandSignal_SignalType_SignalType_ARRAYSIZE = CommandSignal_SignalType_SignalType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* CommandSignal_SignalType_descriptor();
template<typename T>
inline const std::string& CommandSignal_SignalType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, CommandSignal_SignalType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function CommandSignal_SignalType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    CommandSignal_SignalType_descriptor(), enum_t_value);
}
inline bool CommandSignal_SignalType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, CommandSignal_SignalType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<CommandSignal_SignalType>(
    CommandSignal_SignalType_descriptor(), name, value);
}
// ===================================================================

class VehicleSignal_SignalsEntry_DoNotUse : public ::PROTOBUF_NAMESPACE_ID::internal::MapEntry<VehicleSignal_SignalsEntry_DoNotUse, 
    ::PROTOBUF_NAMESPACE_ID::int32, float,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT32,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_FLOAT,
    0 > {
public:
  typedef ::PROTOBUF_NAMESPACE_ID::internal::MapEntry<VehicleSignal_SignalsEntry_DoNotUse, 
    ::PROTOBUF_NAMESPACE_ID::int32, float,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT32,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_FLOAT,
    0 > SuperType;
  VehicleSignal_SignalsEntry_DoNotUse();
  explicit VehicleSignal_SignalsEntry_DoNotUse(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  void MergeFrom(const VehicleSignal_SignalsEntry_DoNotUse& other);
  static const VehicleSignal_SignalsEntry_DoNotUse* internal_default_instance() { return reinterpret_cast<const VehicleSignal_SignalsEntry_DoNotUse*>(&_VehicleSignal_SignalsEntry_DoNotUse_default_instance_); }
  static bool ValidateKey(void*) { return true; }
  static bool ValidateValue(void*) { return true; }
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& other) final;
  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_vehicle_5fsignal_2eproto);
    return ::descriptor_table_vehicle_5fsignal_2eproto.file_level_metadata[0];
  }

  public:
};

// -------------------------------------------------------------------

class VehicleSignal PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:minieye.VehicleSignal) */ {
 public:
  inline VehicleSignal() : VehicleSignal(nullptr) {}
  virtual ~VehicleSignal();

  VehicleSignal(const VehicleSignal& from);
  VehicleSignal(VehicleSignal&& from) noexcept
    : VehicleSignal() {
    *this = ::std::move(from);
  }

  inline VehicleSignal& operator=(const VehicleSignal& from) {
    CopyFrom(from);
    return *this;
  }
  inline VehicleSignal& operator=(VehicleSignal&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const VehicleSignal& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const VehicleSignal* internal_default_instance() {
    return reinterpret_cast<const VehicleSignal*>(
               &_VehicleSignal_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(VehicleSignal& a, VehicleSignal& b) {
    a.Swap(&b);
  }
  inline void Swap(VehicleSignal* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(VehicleSignal* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline VehicleSignal* New() const final {
    return CreateMaybeMessage<VehicleSignal>(nullptr);
  }

  VehicleSignal* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<VehicleSignal>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const VehicleSignal& from);
  void MergeFrom(const VehicleSignal& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(VehicleSignal* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "minieye.VehicleSignal";
  }
  protected:
  explicit VehicleSignal(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_vehicle_5fsignal_2eproto);
    return ::descriptor_table_vehicle_5fsignal_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------


  typedef VehicleSignal_SignalType SignalType;
  static constexpr SignalType kInvalid =
    VehicleSignal_SignalType_kInvalid;
  static constexpr SignalType kSteeringWheelAngle =
    VehicleSignal_SignalType_kSteeringWheelAngle;
  static constexpr SignalType kSteeringWheelDirect =
    VehicleSignal_SignalType_kSteeringWheelDirect;
  static constexpr SignalType kLenkmoment =
    VehicleSignal_SignalType_kLenkmoment;
  static constexpr SignalType kLenkmomentQbit =
    VehicleSignal_SignalType_kLenkmomentQbit;
  static constexpr SignalType kWheelSpeedFl =
    VehicleSignal_SignalType_kWheelSpeedFl;
  static constexpr SignalType kWheelSpeedFlDirect =
    VehicleSignal_SignalType_kWheelSpeedFlDirect;
  static constexpr SignalType kWheelSpeedFr =
    VehicleSignal_SignalType_kWheelSpeedFr;
  static constexpr SignalType kWheelSpeedFrDirect =
    VehicleSignal_SignalType_kWheelSpeedFrDirect;
  static constexpr SignalType kWheelSpeedRl =
    VehicleSignal_SignalType_kWheelSpeedRl;
  static constexpr SignalType kWheelSpeedRlDirect =
    VehicleSignal_SignalType_kWheelSpeedRlDirect;
  static constexpr SignalType kWheelSpeedRr =
    VehicleSignal_SignalType_kWheelSpeedRr;
  static constexpr SignalType kWheelSpeedRrDirect =
    VehicleSignal_SignalType_kWheelSpeedRrDirect;
  static constexpr SignalType kTargetGear =
    VehicleSignal_SignalType_kTargetGear;
  static constexpr SignalType kShortDisRadarFl =
    VehicleSignal_SignalType_kShortDisRadarFl;
  static constexpr SignalType kShortDisRadarFlm =
    VehicleSignal_SignalType_kShortDisRadarFlm;
  static constexpr SignalType kShortDisRadarFrm =
    VehicleSignal_SignalType_kShortDisRadarFrm;
  static constexpr SignalType kShortDisRadarFr =
    VehicleSignal_SignalType_kShortDisRadarFr;
  static constexpr SignalType kShortDisRadarBl =
    VehicleSignal_SignalType_kShortDisRadarBl;
  static constexpr SignalType kShortDisRadarBlm =
    VehicleSignal_SignalType_kShortDisRadarBlm;
  static constexpr SignalType kShortDisRadarBrm =
    VehicleSignal_SignalType_kShortDisRadarBrm;
  static constexpr SignalType kShortDisRadarBr =
    VehicleSignal_SignalType_kShortDisRadarBr;
  static constexpr SignalType kLongDisRadarFl =
    VehicleSignal_SignalType_kLongDisRadarFl;
  static constexpr SignalType kLongDisRadarFr =
    VehicleSignal_SignalType_kLongDisRadarFr;
  static constexpr SignalType kLongDisRadarBl =
    VehicleSignal_SignalType_kLongDisRadarBl;
  static constexpr SignalType kLongDisRadarBr =
    VehicleSignal_SignalType_kLongDisRadarBr;
  static constexpr SignalType kWheelSpeed2Fl =
    VehicleSignal_SignalType_kWheelSpeed2Fl;
  static constexpr SignalType kWheelSpeed2Fr =
    VehicleSignal_SignalType_kWheelSpeed2Fr;
  static constexpr SignalType kWheelSpeed2Rl =
    VehicleSignal_SignalType_kWheelSpeed2Rl;
  static constexpr SignalType kWheelSpeed2Rr =
    VehicleSignal_SignalType_kWheelSpeed2Rr;
  static constexpr SignalType kGierrate =
    VehicleSignal_SignalType_kGierrate;
  static constexpr SignalType kGierrateDirect =
    VehicleSignal_SignalType_kGierrateDirect;
  static constexpr SignalType kLongitudinalAc =
    VehicleSignal_SignalType_kLongitudinalAc;
  static constexpr SignalType kLaterallyAc =
    VehicleSignal_SignalType_kLaterallyAc;
  static constexpr SignalType kPlaStatus =
    VehicleSignal_SignalType_kPlaStatus;
  static constexpr SignalType kPlaResp =
    VehicleSignal_SignalType_kPlaResp;
  static constexpr SignalType kCanSpeed =
    VehicleSignal_SignalType_kCanSpeed;
  static inline bool SignalType_IsValid(int value) {
    return VehicleSignal_SignalType_IsValid(value);
  }
  static constexpr SignalType SignalType_MIN =
    VehicleSignal_SignalType_SignalType_MIN;
  static constexpr SignalType SignalType_MAX =
    VehicleSignal_SignalType_SignalType_MAX;
  static constexpr int SignalType_ARRAYSIZE =
    VehicleSignal_SignalType_SignalType_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  SignalType_descriptor() {
    return VehicleSignal_SignalType_descriptor();
  }
  template<typename T>
  static inline const std::string& SignalType_Name(T enum_t_value) {
    static_assert(::std::is_same<T, SignalType>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function SignalType_Name.");
    return VehicleSignal_SignalType_Name(enum_t_value);
  }
  static inline bool SignalType_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
      SignalType* value) {
    return VehicleSignal_SignalType_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kSignalsFieldNumber = 2,
    kSignalTmFieldNumber = 1,
  };
  // map<int32, float> signals = 2;
  int signals_size() const;
  private:
  int _internal_signals_size() const;
  public:
  void clear_signals();
  private:
  const ::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::int32, float >&
      _internal_signals() const;
  ::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::int32, float >*
      _internal_mutable_signals();
  public:
  const ::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::int32, float >&
      signals() const;
  ::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::int32, float >*
      mutable_signals();

  // uint64 signal_tm = 1;
  void clear_signal_tm();
  ::PROTOBUF_NAMESPACE_ID::uint64 signal_tm() const;
  void set_signal_tm(::PROTOBUF_NAMESPACE_ID::uint64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint64 _internal_signal_tm() const;
  void _internal_set_signal_tm(::PROTOBUF_NAMESPACE_ID::uint64 value);
  public:

  // @@protoc_insertion_point(class_scope:minieye.VehicleSignal)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::MapField<
      VehicleSignal_SignalsEntry_DoNotUse,
      ::PROTOBUF_NAMESPACE_ID::int32, float,
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_INT32,
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_FLOAT,
      0 > signals_;
  ::PROTOBUF_NAMESPACE_ID::uint64 signal_tm_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_vehicle_5fsignal_2eproto;
};
// -------------------------------------------------------------------

class CommandSignal PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:minieye.CommandSignal) */ {
 public:
  inline CommandSignal() : CommandSignal(nullptr) {}
  virtual ~CommandSignal();

  CommandSignal(const CommandSignal& from);
  CommandSignal(CommandSignal&& from) noexcept
    : CommandSignal() {
    *this = ::std::move(from);
  }

  inline CommandSignal& operator=(const CommandSignal& from) {
    CopyFrom(from);
    return *this;
  }
  inline CommandSignal& operator=(CommandSignal&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const CommandSignal& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const CommandSignal* internal_default_instance() {
    return reinterpret_cast<const CommandSignal*>(
               &_CommandSignal_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(CommandSignal& a, CommandSignal& b) {
    a.Swap(&b);
  }
  inline void Swap(CommandSignal* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(CommandSignal* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline CommandSignal* New() const final {
    return CreateMaybeMessage<CommandSignal>(nullptr);
  }

  CommandSignal* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<CommandSignal>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const CommandSignal& from);
  void MergeFrom(const CommandSignal& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(CommandSignal* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "minieye.CommandSignal";
  }
  protected:
  explicit CommandSignal(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_vehicle_5fsignal_2eproto);
    return ::descriptor_table_vehicle_5fsignal_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  typedef CommandSignal_SignalType SignalType;
  static constexpr SignalType kUnknown =
    CommandSignal_SignalType_kUnknown;
  static inline bool SignalType_IsValid(int value) {
    return CommandSignal_SignalType_IsValid(value);
  }
  static constexpr SignalType SignalType_MIN =
    CommandSignal_SignalType_SignalType_MIN;
  static constexpr SignalType SignalType_MAX =
    CommandSignal_SignalType_SignalType_MAX;
  static constexpr int SignalType_ARRAYSIZE =
    CommandSignal_SignalType_SignalType_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  SignalType_descriptor() {
    return CommandSignal_SignalType_descriptor();
  }
  template<typename T>
  static inline const std::string& SignalType_Name(T enum_t_value) {
    static_assert(::std::is_same<T, SignalType>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function SignalType_Name.");
    return CommandSignal_SignalType_Name(enum_t_value);
  }
  static inline bool SignalType_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
      SignalType* value) {
    return CommandSignal_SignalType_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kDetailsFieldNumber = 2,
    kSignalFieldNumber = 1,
  };
  // .google.protobuf.Any details = 2;
  bool has_details() const;
  private:
  bool _internal_has_details() const;
  public:
  void clear_details();
  const PROTOBUF_NAMESPACE_ID::Any& details() const;
  PROTOBUF_NAMESPACE_ID::Any* release_details();
  PROTOBUF_NAMESPACE_ID::Any* mutable_details();
  void set_allocated_details(PROTOBUF_NAMESPACE_ID::Any* details);
  private:
  const PROTOBUF_NAMESPACE_ID::Any& _internal_details() const;
  PROTOBUF_NAMESPACE_ID::Any* _internal_mutable_details();
  public:
  void unsafe_arena_set_allocated_details(
      PROTOBUF_NAMESPACE_ID::Any* details);
  PROTOBUF_NAMESPACE_ID::Any* unsafe_arena_release_details();

  // .minieye.CommandSignal.SignalType signal = 1;
  void clear_signal();
  ::minieye::CommandSignal_SignalType signal() const;
  void set_signal(::minieye::CommandSignal_SignalType value);
  private:
  ::minieye::CommandSignal_SignalType _internal_signal() const;
  void _internal_set_signal(::minieye::CommandSignal_SignalType value);
  public:

  // @@protoc_insertion_point(class_scope:minieye.CommandSignal)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  PROTOBUF_NAMESPACE_ID::Any* details_;
  int signal_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_vehicle_5fsignal_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// VehicleSignal

// uint64 signal_tm = 1;
inline void VehicleSignal::clear_signal_tm() {
  signal_tm_ = PROTOBUF_ULONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 VehicleSignal::_internal_signal_tm() const {
  return signal_tm_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 VehicleSignal::signal_tm() const {
  // @@protoc_insertion_point(field_get:minieye.VehicleSignal.signal_tm)
  return _internal_signal_tm();
}
inline void VehicleSignal::_internal_set_signal_tm(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  
  signal_tm_ = value;
}
inline void VehicleSignal::set_signal_tm(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _internal_set_signal_tm(value);
  // @@protoc_insertion_point(field_set:minieye.VehicleSignal.signal_tm)
}

// map<int32, float> signals = 2;
inline int VehicleSignal::_internal_signals_size() const {
  return signals_.size();
}
inline int VehicleSignal::signals_size() const {
  return _internal_signals_size();
}
inline void VehicleSignal::clear_signals() {
  signals_.Clear();
}
inline const ::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::int32, float >&
VehicleSignal::_internal_signals() const {
  return signals_.GetMap();
}
inline const ::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::int32, float >&
VehicleSignal::signals() const {
  // @@protoc_insertion_point(field_map:minieye.VehicleSignal.signals)
  return _internal_signals();
}
inline ::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::int32, float >*
VehicleSignal::_internal_mutable_signals() {
  return signals_.MutableMap();
}
inline ::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::int32, float >*
VehicleSignal::mutable_signals() {
  // @@protoc_insertion_point(field_mutable_map:minieye.VehicleSignal.signals)
  return _internal_mutable_signals();
}

// -------------------------------------------------------------------

// CommandSignal

// .minieye.CommandSignal.SignalType signal = 1;
inline void CommandSignal::clear_signal() {
  signal_ = 0;
}
inline ::minieye::CommandSignal_SignalType CommandSignal::_internal_signal() const {
  return static_cast< ::minieye::CommandSignal_SignalType >(signal_);
}
inline ::minieye::CommandSignal_SignalType CommandSignal::signal() const {
  // @@protoc_insertion_point(field_get:minieye.CommandSignal.signal)
  return _internal_signal();
}
inline void CommandSignal::_internal_set_signal(::minieye::CommandSignal_SignalType value) {
  
  signal_ = value;
}
inline void CommandSignal::set_signal(::minieye::CommandSignal_SignalType value) {
  _internal_set_signal(value);
  // @@protoc_insertion_point(field_set:minieye.CommandSignal.signal)
}

// .google.protobuf.Any details = 2;
inline bool CommandSignal::_internal_has_details() const {
  return this != internal_default_instance() && details_ != nullptr;
}
inline bool CommandSignal::has_details() const {
  return _internal_has_details();
}
inline const PROTOBUF_NAMESPACE_ID::Any& CommandSignal::_internal_details() const {
  const PROTOBUF_NAMESPACE_ID::Any* p = details_;
  return p != nullptr ? *p : *reinterpret_cast<const PROTOBUF_NAMESPACE_ID::Any*>(
      &PROTOBUF_NAMESPACE_ID::_Any_default_instance_);
}
inline const PROTOBUF_NAMESPACE_ID::Any& CommandSignal::details() const {
  // @@protoc_insertion_point(field_get:minieye.CommandSignal.details)
  return _internal_details();
}
inline void CommandSignal::unsafe_arena_set_allocated_details(
    PROTOBUF_NAMESPACE_ID::Any* details) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(details_);
  }
  details_ = details;
  if (details) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:minieye.CommandSignal.details)
}
inline PROTOBUF_NAMESPACE_ID::Any* CommandSignal::release_details() {
  
  PROTOBUF_NAMESPACE_ID::Any* temp = details_;
  details_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline PROTOBUF_NAMESPACE_ID::Any* CommandSignal::unsafe_arena_release_details() {
  // @@protoc_insertion_point(field_release:minieye.CommandSignal.details)
  
  PROTOBUF_NAMESPACE_ID::Any* temp = details_;
  details_ = nullptr;
  return temp;
}
inline PROTOBUF_NAMESPACE_ID::Any* CommandSignal::_internal_mutable_details() {
  
  if (details_ == nullptr) {
    auto* p = CreateMaybeMessage<PROTOBUF_NAMESPACE_ID::Any>(GetArena());
    details_ = p;
  }
  return details_;
}
inline PROTOBUF_NAMESPACE_ID::Any* CommandSignal::mutable_details() {
  // @@protoc_insertion_point(field_mutable:minieye.CommandSignal.details)
  return _internal_mutable_details();
}
inline void CommandSignal::set_allocated_details(PROTOBUF_NAMESPACE_ID::Any* details) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(details_);
  }
  if (details) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(details)->GetArena();
    if (message_arena != submessage_arena) {
      details = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, details, submessage_arena);
    }
    
  } else {
    
  }
  details_ = details;
  // @@protoc_insertion_point(field_set_allocated:minieye.CommandSignal.details)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace minieye

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::minieye::VehicleSignal_SignalType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::minieye::VehicleSignal_SignalType>() {
  return ::minieye::VehicleSignal_SignalType_descriptor();
}
template <> struct is_proto_enum< ::minieye::CommandSignal_SignalType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::minieye::CommandSignal_SignalType>() {
  return ::minieye::CommandSignal_SignalType_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_vehicle_5fsignal_2eproto