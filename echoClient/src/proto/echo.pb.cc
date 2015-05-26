// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/echo.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "proto/echo.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace echo {

namespace {

const ::google::protobuf::Descriptor* EchoReq_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  EchoReq_reflection_ = NULL;
const ::google::protobuf::Descriptor* EchoRes_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  EchoRes_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* MType_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_proto_2fecho_2eproto() {
  protobuf_AddDesc_proto_2fecho_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "proto/echo.proto");
  GOOGLE_CHECK(file != NULL);
  EchoReq_descriptor_ = file->message_type(0);
  static const int EchoReq_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EchoReq, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EchoReq, req_),
  };
  EchoReq_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      EchoReq_descriptor_,
      EchoReq::default_instance_,
      EchoReq_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EchoReq, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EchoReq, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(EchoReq));
  EchoRes_descriptor_ = file->message_type(1);
  static const int EchoRes_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EchoRes, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EchoRes, res_),
  };
  EchoRes_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      EchoRes_descriptor_,
      EchoRes::default_instance_,
      EchoRes_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EchoRes, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EchoRes, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(EchoRes));
  MType_descriptor_ = file->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_proto_2fecho_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    EchoReq_descriptor_, &EchoReq::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    EchoRes_descriptor_, &EchoRes::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_proto_2fecho_2eproto() {
  delete EchoReq::default_instance_;
  delete EchoReq_reflection_;
  delete EchoRes::default_instance_;
  delete EchoRes_reflection_;
}

void protobuf_AddDesc_proto_2fecho_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\020proto/echo.proto\022\004echo\"1\n\007EchoReq\022\031\n\004t"
    "ype\030\001 \002(\0162\013.echo.MType\022\013\n\003req\030\002 \002(\t\"1\n\007E"
    "choRes\022\031\n\004type\030\001 \002(\0162\013.echo.MType\022\013\n\003res"
    "\030\002 \002(\t*\021\n\005MType\022\010\n\004ECHO\020\001", 145);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "proto/echo.proto", &protobuf_RegisterTypes);
  EchoReq::default_instance_ = new EchoReq();
  EchoRes::default_instance_ = new EchoRes();
  EchoReq::default_instance_->InitAsDefaultInstance();
  EchoRes::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_proto_2fecho_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_proto_2fecho_2eproto {
  StaticDescriptorInitializer_proto_2fecho_2eproto() {
    protobuf_AddDesc_proto_2fecho_2eproto();
  }
} static_descriptor_initializer_proto_2fecho_2eproto_;
const ::google::protobuf::EnumDescriptor* MType_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MType_descriptor_;
}
bool MType_IsValid(int value) {
  switch(value) {
    case 1:
      return true;
    default:
      return false;
  }
}


// ===================================================================

#ifndef _MSC_VER
const int EchoReq::kTypeFieldNumber;
const int EchoReq::kReqFieldNumber;
#endif  // !_MSC_VER

EchoReq::EchoReq()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:echo.EchoReq)
}

void EchoReq::InitAsDefaultInstance() {
}

EchoReq::EchoReq(const EchoReq& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:echo.EchoReq)
}

void EchoReq::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  type_ = 1;
  req_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

EchoReq::~EchoReq() {
  // @@protoc_insertion_point(destructor:echo.EchoReq)
  SharedDtor();
}

void EchoReq::SharedDtor() {
  if (req_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete req_;
  }
  if (this != default_instance_) {
  }
}

void EchoReq::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* EchoReq::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return EchoReq_descriptor_;
}

const EchoReq& EchoReq::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_proto_2fecho_2eproto();
  return *default_instance_;
}

EchoReq* EchoReq::default_instance_ = NULL;

EchoReq* EchoReq::New() const {
  return new EchoReq;
}

void EchoReq::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    type_ = 1;
    if (has_req()) {
      if (req_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        req_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool EchoReq::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:echo.EchoReq)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .echo.MType type = 1;
      case 1: {
        if (tag == 8) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::echo::MType_IsValid(value)) {
            set_type(static_cast< ::echo::MType >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_req;
        break;
      }

      // required string req = 2;
      case 2: {
        if (tag == 18) {
         parse_req:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_req()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->req().data(), this->req().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "req");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:echo.EchoReq)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:echo.EchoReq)
  return false;
#undef DO_
}

void EchoReq::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:echo.EchoReq)
  // required .echo.MType type = 1;
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->type(), output);
  }

  // required string req = 2;
  if (has_req()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->req().data(), this->req().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "req");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->req(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:echo.EchoReq)
}

::google::protobuf::uint8* EchoReq::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:echo.EchoReq)
  // required .echo.MType type = 1;
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->type(), target);
  }

  // required string req = 2;
  if (has_req()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->req().data(), this->req().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "req");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->req(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:echo.EchoReq)
  return target;
}

int EchoReq::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .echo.MType type = 1;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->type());
    }

    // required string req = 2;
    if (has_req()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->req());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void EchoReq::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const EchoReq* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const EchoReq*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void EchoReq::MergeFrom(const EchoReq& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_type()) {
      set_type(from.type());
    }
    if (from.has_req()) {
      set_req(from.req());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void EchoReq::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void EchoReq::CopyFrom(const EchoReq& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool EchoReq::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void EchoReq::Swap(EchoReq* other) {
  if (other != this) {
    std::swap(type_, other->type_);
    std::swap(req_, other->req_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata EchoReq::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = EchoReq_descriptor_;
  metadata.reflection = EchoReq_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int EchoRes::kTypeFieldNumber;
const int EchoRes::kResFieldNumber;
#endif  // !_MSC_VER

EchoRes::EchoRes()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:echo.EchoRes)
}

void EchoRes::InitAsDefaultInstance() {
}

EchoRes::EchoRes(const EchoRes& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:echo.EchoRes)
}

void EchoRes::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  type_ = 1;
  res_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

EchoRes::~EchoRes() {
  // @@protoc_insertion_point(destructor:echo.EchoRes)
  SharedDtor();
}

void EchoRes::SharedDtor() {
  if (res_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete res_;
  }
  if (this != default_instance_) {
  }
}

void EchoRes::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* EchoRes::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return EchoRes_descriptor_;
}

const EchoRes& EchoRes::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_proto_2fecho_2eproto();
  return *default_instance_;
}

EchoRes* EchoRes::default_instance_ = NULL;

EchoRes* EchoRes::New() const {
  return new EchoRes;
}

void EchoRes::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    type_ = 1;
    if (has_res()) {
      if (res_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        res_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool EchoRes::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:echo.EchoRes)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .echo.MType type = 1;
      case 1: {
        if (tag == 8) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::echo::MType_IsValid(value)) {
            set_type(static_cast< ::echo::MType >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_res;
        break;
      }

      // required string res = 2;
      case 2: {
        if (tag == 18) {
         parse_res:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_res()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->res().data(), this->res().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "res");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:echo.EchoRes)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:echo.EchoRes)
  return false;
#undef DO_
}

void EchoRes::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:echo.EchoRes)
  // required .echo.MType type = 1;
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->type(), output);
  }

  // required string res = 2;
  if (has_res()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->res().data(), this->res().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "res");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->res(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:echo.EchoRes)
}

::google::protobuf::uint8* EchoRes::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:echo.EchoRes)
  // required .echo.MType type = 1;
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->type(), target);
  }

  // required string res = 2;
  if (has_res()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->res().data(), this->res().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "res");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->res(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:echo.EchoRes)
  return target;
}

int EchoRes::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .echo.MType type = 1;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->type());
    }

    // required string res = 2;
    if (has_res()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->res());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void EchoRes::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const EchoRes* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const EchoRes*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void EchoRes::MergeFrom(const EchoRes& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_type()) {
      set_type(from.type());
    }
    if (from.has_res()) {
      set_res(from.res());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void EchoRes::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void EchoRes::CopyFrom(const EchoRes& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool EchoRes::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void EchoRes::Swap(EchoRes* other) {
  if (other != this) {
    std::swap(type_, other->type_);
    std::swap(res_, other->res_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata EchoRes::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = EchoRes_descriptor_;
  metadata.reflection = EchoRes_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace echo

// @@protoc_insertion_point(global_scope)
