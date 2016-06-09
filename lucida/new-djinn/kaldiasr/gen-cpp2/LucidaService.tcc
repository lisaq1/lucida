/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include "LucidaService.h"
#include <thrift/lib/cpp/TApplicationException.h>
#include <folly/io/IOBuf.h>
#include <folly/io/IOBufQueue.h>
#include <thrift/lib/cpp/transport/THeader.h>
#include <thrift/lib/cpp2/server/Cpp2ConnContext.h>
#include <thrift/lib/cpp2/GeneratedCodeHelper.h>

namespace cpp2 {

typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, apache::thrift::protocol::T_STRING, std::string*>, apache::thrift::FieldData<2, apache::thrift::protocol::T_STRUCT,  ::cpp2::QuerySpec*>> LucidaService_create_pargs;
typedef apache::thrift::ThriftPresult<true> LucidaService_create_presult;
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, apache::thrift::protocol::T_STRING, std::string*>, apache::thrift::FieldData<2, apache::thrift::protocol::T_STRUCT,  ::cpp2::QuerySpec*>> LucidaService_learn_pargs;
typedef apache::thrift::ThriftPresult<true> LucidaService_learn_presult;
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, apache::thrift::protocol::T_STRING, std::string*>, apache::thrift::FieldData<2, apache::thrift::protocol::T_STRUCT,  ::cpp2::QuerySpec*>> LucidaService_infer_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, apache::thrift::protocol::T_STRING, std::string*>> LucidaService_infer_presult;
template <typename ProtocolIn_, typename ProtocolOut_>
void LucidaServiceAsyncProcessor::_processInThread_create(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(buf),std::move(iprot), ctx, eb, tm, pri, false, &LucidaServiceAsyncProcessor::process_create<ProtocolIn_, ProtocolOut_>, this);
}

template <typename ProtocolIn_, typename ProtocolOut_>
void LucidaServiceAsyncProcessor::process_create(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot,apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  LucidaService_create_pargs args;
  std::unique_ptr<std::string> uarg_LUCID(new std::string());
  args.get<0>().value = uarg_LUCID.get();
  std::unique_ptr< ::cpp2::QuerySpec> uarg_spec(new  ::cpp2::QuerySpec());
  args.get<1>().value = uarg_spec.get();
  std::unique_ptr<apache::thrift::ContextStack> c(this->getContextStack(this->getServiceName(), "LucidaService.create", ctx));
  try {
    deserializeRequest(args, buf.get(), iprot.get(), c.get());
  }
  catch (const std::exception& ex) {
    ProtocolOut_ prot;
    if (req) {
      LOG(ERROR) << ex.what() << " in function create";
      apache::thrift::TApplicationException x(apache::thrift::TApplicationException::TApplicationExceptionType::PROTOCOL_ERROR, ex.what());
      folly::IOBufQueue queue = serializeException("create", &prot, ctx->getProtoSeqId(), nullptr, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), ctx->getHeader()->getWriteTransforms(), ctx->getHeader()->getMinCompressBytes()));
      eb->runInEventBaseThread([queue = std::move(queue), req = std::move(req)]() mutable {
        req->sendReply(queue.move());
      }
      );
      return;
    }
    else {
      LOG(ERROR) << ex.what() << " in oneway function create";
    }
  }
  auto callback = folly::make_unique<apache::thrift::HandlerCallback<void>>(std::move(req), std::move(c), return_create<ProtocolIn_,ProtocolOut_>, throw_create<ProtocolIn_, ProtocolOut_>, throw_wrapped_create<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  if (!callback->isRequestActive()) {
    callback.release()->deleteInThread();
    return;
  }
  ctx->setStartedProcessing();
  iface_->async_tm_create(std::move(callback), std::move(uarg_LUCID), std::move(uarg_spec));
}

template <class ProtocolIn_, class ProtocolOut_>
folly::IOBufQueue LucidaServiceAsyncProcessor::return_create(int32_t protoSeqId, apache::thrift::ContextStack* ctx) {
  ProtocolOut_ prot;
  LucidaService_create_presult result;
  return serializeResponse("create", &prot, protoSeqId, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void LucidaServiceAsyncProcessor::throw_create(std::unique_ptr<apache::thrift::ResponseChannel::Request> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,std::exception_ptr ep,apache::thrift::Cpp2RequestContext* reqCtx) {
  ProtocolOut_ prot;
  try {
    std::rethrow_exception(ep);
  }
  catch (const std::exception& e) {
    auto ew = folly::exception_wrapper(ep, e);
    if (req) {
      LOG(ERROR) << folly::exceptionStr(e).toStdString() << " in function create";
      apache::thrift::TApplicationException x(folly::exceptionStr(e).toStdString());
      ctx->userExceptionWrapped(false, ew);
      ctx->handlerErrorWrapped(ew);
      folly::IOBufQueue queue = serializeException("create", &prot, protoSeqId, ctx, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
      req->sendReply(queue.move());
      return;
    }
    else {
      LOG(ERROR) << folly::exceptionStr(e).toStdString() << " in oneway function create";
    }
  }
  catch (...) {
    if (req) {
      LOG(ERROR) << "<unknown exception>" << " in function create";
      apache::thrift::TApplicationException x("<unknown exception>");
      folly::IOBufQueue queue = serializeException("create", &prot, protoSeqId, nullptr, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
      req->sendReply(queue.move());
      return;
    }
    else {
      LOG(ERROR) << "<unknown exception>" << " in oneway function create";
    }
  }
}

template <class ProtocolIn_, class ProtocolOut_>
void LucidaServiceAsyncProcessor::throw_wrapped_create(std::unique_ptr<apache::thrift::ResponseChannel::Request> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  ProtocolOut_ prot;
   {
    if (req) {
      LOG(ERROR) << ew.what().toStdString() << " in function create";
      apache::thrift::TApplicationException x(ew.what().toStdString());
      ctx->userExceptionWrapped(false, ew);
      ctx->handlerErrorWrapped(ew);
      folly::IOBufQueue queue = serializeException("create", &prot, protoSeqId, ctx, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
      req->sendReply(queue.move());
      return;
    }
    else {
      LOG(ERROR) << ew.what().toStdString() << " in oneway function create";
    }
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void LucidaServiceAsyncProcessor::_processInThread_learn(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(buf),std::move(iprot), ctx, eb, tm, pri, false, &LucidaServiceAsyncProcessor::process_learn<ProtocolIn_, ProtocolOut_>, this);
}

template <typename ProtocolIn_, typename ProtocolOut_>
void LucidaServiceAsyncProcessor::process_learn(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot,apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  LucidaService_learn_pargs args;
  std::unique_ptr<std::string> uarg_LUCID(new std::string());
  args.get<0>().value = uarg_LUCID.get();
  std::unique_ptr< ::cpp2::QuerySpec> uarg_knowledge(new  ::cpp2::QuerySpec());
  args.get<1>().value = uarg_knowledge.get();
  std::unique_ptr<apache::thrift::ContextStack> c(this->getContextStack(this->getServiceName(), "LucidaService.learn", ctx));
  try {
    deserializeRequest(args, buf.get(), iprot.get(), c.get());
  }
  catch (const std::exception& ex) {
    ProtocolOut_ prot;
    if (req) {
      LOG(ERROR) << ex.what() << " in function learn";
      apache::thrift::TApplicationException x(apache::thrift::TApplicationException::TApplicationExceptionType::PROTOCOL_ERROR, ex.what());
      folly::IOBufQueue queue = serializeException("learn", &prot, ctx->getProtoSeqId(), nullptr, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), ctx->getHeader()->getWriteTransforms(), ctx->getHeader()->getMinCompressBytes()));
      eb->runInEventBaseThread([queue = std::move(queue), req = std::move(req)]() mutable {
        req->sendReply(queue.move());
      }
      );
      return;
    }
    else {
      LOG(ERROR) << ex.what() << " in oneway function learn";
    }
  }
  auto callback = folly::make_unique<apache::thrift::HandlerCallback<void>>(std::move(req), std::move(c), return_learn<ProtocolIn_,ProtocolOut_>, throw_learn<ProtocolIn_, ProtocolOut_>, throw_wrapped_learn<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  if (!callback->isRequestActive()) {
    callback.release()->deleteInThread();
    return;
  }
  ctx->setStartedProcessing();
  iface_->async_tm_learn(std::move(callback), std::move(uarg_LUCID), std::move(uarg_knowledge));
}

template <class ProtocolIn_, class ProtocolOut_>
folly::IOBufQueue LucidaServiceAsyncProcessor::return_learn(int32_t protoSeqId, apache::thrift::ContextStack* ctx) {
  ProtocolOut_ prot;
  LucidaService_learn_presult result;
  return serializeResponse("learn", &prot, protoSeqId, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void LucidaServiceAsyncProcessor::throw_learn(std::unique_ptr<apache::thrift::ResponseChannel::Request> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,std::exception_ptr ep,apache::thrift::Cpp2RequestContext* reqCtx) {
  ProtocolOut_ prot;
  try {
    std::rethrow_exception(ep);
  }
  catch (const std::exception& e) {
    auto ew = folly::exception_wrapper(ep, e);
    if (req) {
      LOG(ERROR) << folly::exceptionStr(e).toStdString() << " in function learn";
      apache::thrift::TApplicationException x(folly::exceptionStr(e).toStdString());
      ctx->userExceptionWrapped(false, ew);
      ctx->handlerErrorWrapped(ew);
      folly::IOBufQueue queue = serializeException("learn", &prot, protoSeqId, ctx, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
      req->sendReply(queue.move());
      return;
    }
    else {
      LOG(ERROR) << folly::exceptionStr(e).toStdString() << " in oneway function learn";
    }
  }
  catch (...) {
    if (req) {
      LOG(ERROR) << "<unknown exception>" << " in function learn";
      apache::thrift::TApplicationException x("<unknown exception>");
      folly::IOBufQueue queue = serializeException("learn", &prot, protoSeqId, nullptr, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
      req->sendReply(queue.move());
      return;
    }
    else {
      LOG(ERROR) << "<unknown exception>" << " in oneway function learn";
    }
  }
}

template <class ProtocolIn_, class ProtocolOut_>
void LucidaServiceAsyncProcessor::throw_wrapped_learn(std::unique_ptr<apache::thrift::ResponseChannel::Request> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  ProtocolOut_ prot;
   {
    if (req) {
      LOG(ERROR) << ew.what().toStdString() << " in function learn";
      apache::thrift::TApplicationException x(ew.what().toStdString());
      ctx->userExceptionWrapped(false, ew);
      ctx->handlerErrorWrapped(ew);
      folly::IOBufQueue queue = serializeException("learn", &prot, protoSeqId, ctx, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
      req->sendReply(queue.move());
      return;
    }
    else {
      LOG(ERROR) << ew.what().toStdString() << " in oneway function learn";
    }
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void LucidaServiceAsyncProcessor::_processInThread_infer(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(buf),std::move(iprot), ctx, eb, tm, pri, false, &LucidaServiceAsyncProcessor::process_infer<ProtocolIn_, ProtocolOut_>, this);
}

template <typename ProtocolIn_, typename ProtocolOut_>
void LucidaServiceAsyncProcessor::process_infer(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot,apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  LucidaService_infer_pargs args;
  std::unique_ptr<std::string> uarg_LUCID(new std::string());
  args.get<0>().value = uarg_LUCID.get();
  std::unique_ptr< ::cpp2::QuerySpec> uarg_query(new  ::cpp2::QuerySpec());
  args.get<1>().value = uarg_query.get();
  std::unique_ptr<apache::thrift::ContextStack> c(this->getContextStack(this->getServiceName(), "LucidaService.infer", ctx));
  try {
    deserializeRequest(args, buf.get(), iprot.get(), c.get());
  }
  catch (const std::exception& ex) {
    ProtocolOut_ prot;
    if (req) {
      LOG(ERROR) << ex.what() << " in function infer";
      apache::thrift::TApplicationException x(apache::thrift::TApplicationException::TApplicationExceptionType::PROTOCOL_ERROR, ex.what());
      folly::IOBufQueue queue = serializeException("infer", &prot, ctx->getProtoSeqId(), nullptr, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), ctx->getHeader()->getWriteTransforms(), ctx->getHeader()->getMinCompressBytes()));
      eb->runInEventBaseThread([queue = std::move(queue), req = std::move(req)]() mutable {
        req->sendReply(queue.move());
      }
      );
      return;
    }
    else {
      LOG(ERROR) << ex.what() << " in oneway function infer";
    }
  }
  auto callback = folly::make_unique<apache::thrift::HandlerCallback<std::unique_ptr<std::string>>>(std::move(req), std::move(c), return_infer<ProtocolIn_,ProtocolOut_>, throw_infer<ProtocolIn_, ProtocolOut_>, throw_wrapped_infer<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  if (!callback->isRequestActive()) {
    callback.release()->deleteInThread();
    return;
  }
  ctx->setStartedProcessing();
  iface_->async_tm_infer(std::move(callback), std::move(uarg_LUCID), std::move(uarg_query));
}

template <class ProtocolIn_, class ProtocolOut_>
folly::IOBufQueue LucidaServiceAsyncProcessor::return_infer(int32_t protoSeqId, apache::thrift::ContextStack* ctx, std::string const& _return) {
  ProtocolOut_ prot;
  LucidaService_infer_presult result;
  result.get<0>().value = const_cast<std::string*>(&_return);
  result.setIsSet(0, true);
  return serializeResponse("infer", &prot, protoSeqId, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void LucidaServiceAsyncProcessor::throw_infer(std::unique_ptr<apache::thrift::ResponseChannel::Request> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,std::exception_ptr ep,apache::thrift::Cpp2RequestContext* reqCtx) {
  ProtocolOut_ prot;
  try {
    std::rethrow_exception(ep);
  }
  catch (const std::exception& e) {
    auto ew = folly::exception_wrapper(ep, e);
    if (req) {
      LOG(ERROR) << folly::exceptionStr(e).toStdString() << " in function infer";
      apache::thrift::TApplicationException x(folly::exceptionStr(e).toStdString());
      ctx->userExceptionWrapped(false, ew);
      ctx->handlerErrorWrapped(ew);
      folly::IOBufQueue queue = serializeException("infer", &prot, protoSeqId, ctx, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
      req->sendReply(queue.move());
      return;
    }
    else {
      LOG(ERROR) << folly::exceptionStr(e).toStdString() << " in oneway function infer";
    }
  }
  catch (...) {
    if (req) {
      LOG(ERROR) << "<unknown exception>" << " in function infer";
      apache::thrift::TApplicationException x("<unknown exception>");
      folly::IOBufQueue queue = serializeException("infer", &prot, protoSeqId, nullptr, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
      req->sendReply(queue.move());
      return;
    }
    else {
      LOG(ERROR) << "<unknown exception>" << " in oneway function infer";
    }
  }
}

template <class ProtocolIn_, class ProtocolOut_>
void LucidaServiceAsyncProcessor::throw_wrapped_infer(std::unique_ptr<apache::thrift::ResponseChannel::Request> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  ProtocolOut_ prot;
   {
    if (req) {
      LOG(ERROR) << ew.what().toStdString() << " in function infer";
      apache::thrift::TApplicationException x(ew.what().toStdString());
      ctx->userExceptionWrapped(false, ew);
      ctx->handlerErrorWrapped(ew);
      folly::IOBufQueue queue = serializeException("infer", &prot, protoSeqId, ctx, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
      req->sendReply(queue.move());
      return;
    }
    else {
      LOG(ERROR) << ew.what().toStdString() << " in oneway function infer";
    }
  }
}

template <typename Protocol_>
void LucidaServiceAsyncClient::createT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const std::string& LUCID, const  ::cpp2::QuerySpec& spec) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(getChannel()->getProtocolId());
  header->setHeaders(rpcOptions.releaseWriteHeaders());
  connectionContext_->setRequestHeader(header.get());
  std::unique_ptr<apache::thrift::ContextStack> ctx = this->getContextStack(this->getServiceName(), "LucidaService.create", connectionContext_.get());
  LucidaService_create_pargs args;
  args.get<0>().value = const_cast<std::string*>(&LUCID);
  args.get<1>().value = const_cast< ::cpp2::QuerySpec*>(&spec);
  apache::thrift::clientSendT<false>(prot, rpcOptions, std::move(callback), std::move(ctx), header, channel_.get(), args, "create", [](Protocol_* prot, LucidaService_create_pargs& args) { args.write(prot); }, [](Protocol_* prot, LucidaService_create_pargs& args) { return args.serializedSizeZC(prot); });
  connectionContext_->setRequestHeader(nullptr);
}

template <typename Protocol_>
folly::exception_wrapper LucidaServiceAsyncClient::recv_wrapped_createT(Protocol_* prot, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return state.exceptionWrapper();
  }
  prot->setInput(state.buf());
  auto guard = folly::makeGuard([&] {prot->setInput(nullptr);});
  apache::thrift::ContextStack* ctx = state.ctx();
  std::string fname;
  int32_t protoSeqId = 0;
  apache::thrift::MessageType mtype;
  ctx->preRead();
  folly::exception_wrapper interior_ew;
  auto caught_ew = folly::try_and_catch<std::exception, apache::thrift::TException, apache::thrift::protocol::TProtocolException>([&]() {
    prot->readMessageBegin(fname, mtype, protoSeqId);
    if (mtype == apache::thrift::T_EXCEPTION) {
      apache::thrift::TApplicationException x;
      x.read(prot);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(x);
      return; // from try_and_catch
    }
    if (mtype != apache::thrift::T_REPLY) {
      prot->skip(apache::thrift::protocol::T_STRUCT);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::INVALID_MESSAGE_TYPE);
      return; // from try_and_catch
    }
    if (fname.compare("create") != 0) {
      prot->skip(apache::thrift::protocol::T_STRUCT);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::WRONG_METHOD_NAME);
      return; // from try_and_catch
    }
    ::apache::thrift::SerializedMessage smsg;
    smsg.protocolType = prot->protocolType();
    smsg.buffer = state.buf();
    ctx->onReadData(smsg);
    LucidaService_create_presult result;
    result.read(prot);
    prot->readMessageEnd();
    ctx->postRead(state.header(), state.buf()->length());
  }
  );
  auto ew = interior_ew ? std::move(interior_ew) : std::move(caught_ew);
  if (ew) {
    ctx->handlerErrorWrapped(ew);
  }
  return ew;
}

template <typename Protocol_>
void LucidaServiceAsyncClient::recv_createT(Protocol_* prot, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_createT(prot, state);
  if (ew) {
    ew.throwException();
  }
}

template <typename Protocol_>
void LucidaServiceAsyncClient::learnT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const std::string& LUCID, const  ::cpp2::QuerySpec& knowledge) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(getChannel()->getProtocolId());
  header->setHeaders(rpcOptions.releaseWriteHeaders());
  connectionContext_->setRequestHeader(header.get());
  std::unique_ptr<apache::thrift::ContextStack> ctx = this->getContextStack(this->getServiceName(), "LucidaService.learn", connectionContext_.get());
  LucidaService_learn_pargs args;
  args.get<0>().value = const_cast<std::string*>(&LUCID);
  args.get<1>().value = const_cast< ::cpp2::QuerySpec*>(&knowledge);
  apache::thrift::clientSendT<false>(prot, rpcOptions, std::move(callback), std::move(ctx), header, channel_.get(), args, "learn", [](Protocol_* prot, LucidaService_learn_pargs& args) { args.write(prot); }, [](Protocol_* prot, LucidaService_learn_pargs& args) { return args.serializedSizeZC(prot); });
  connectionContext_->setRequestHeader(nullptr);
}

template <typename Protocol_>
folly::exception_wrapper LucidaServiceAsyncClient::recv_wrapped_learnT(Protocol_* prot, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return state.exceptionWrapper();
  }
  prot->setInput(state.buf());
  auto guard = folly::makeGuard([&] {prot->setInput(nullptr);});
  apache::thrift::ContextStack* ctx = state.ctx();
  std::string fname;
  int32_t protoSeqId = 0;
  apache::thrift::MessageType mtype;
  ctx->preRead();
  folly::exception_wrapper interior_ew;
  auto caught_ew = folly::try_and_catch<std::exception, apache::thrift::TException, apache::thrift::protocol::TProtocolException>([&]() {
    prot->readMessageBegin(fname, mtype, protoSeqId);
    if (mtype == apache::thrift::T_EXCEPTION) {
      apache::thrift::TApplicationException x;
      x.read(prot);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(x);
      return; // from try_and_catch
    }
    if (mtype != apache::thrift::T_REPLY) {
      prot->skip(apache::thrift::protocol::T_STRUCT);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::INVALID_MESSAGE_TYPE);
      return; // from try_and_catch
    }
    if (fname.compare("learn") != 0) {
      prot->skip(apache::thrift::protocol::T_STRUCT);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::WRONG_METHOD_NAME);
      return; // from try_and_catch
    }
    ::apache::thrift::SerializedMessage smsg;
    smsg.protocolType = prot->protocolType();
    smsg.buffer = state.buf();
    ctx->onReadData(smsg);
    LucidaService_learn_presult result;
    result.read(prot);
    prot->readMessageEnd();
    ctx->postRead(state.header(), state.buf()->length());
  }
  );
  auto ew = interior_ew ? std::move(interior_ew) : std::move(caught_ew);
  if (ew) {
    ctx->handlerErrorWrapped(ew);
  }
  return ew;
}

template <typename Protocol_>
void LucidaServiceAsyncClient::recv_learnT(Protocol_* prot, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_learnT(prot, state);
  if (ew) {
    ew.throwException();
  }
}

template <typename Protocol_>
void LucidaServiceAsyncClient::inferT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const std::string& LUCID, const  ::cpp2::QuerySpec& query) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(getChannel()->getProtocolId());
  header->setHeaders(rpcOptions.releaseWriteHeaders());
  connectionContext_->setRequestHeader(header.get());
  std::unique_ptr<apache::thrift::ContextStack> ctx = this->getContextStack(this->getServiceName(), "LucidaService.infer", connectionContext_.get());
  LucidaService_infer_pargs args;
  args.get<0>().value = const_cast<std::string*>(&LUCID);
  args.get<1>().value = const_cast< ::cpp2::QuerySpec*>(&query);
  apache::thrift::clientSendT<false>(prot, rpcOptions, std::move(callback), std::move(ctx), header, channel_.get(), args, "infer", [](Protocol_* prot, LucidaService_infer_pargs& args) { args.write(prot); }, [](Protocol_* prot, LucidaService_infer_pargs& args) { return args.serializedSizeZC(prot); });
  connectionContext_->setRequestHeader(nullptr);
}

template <typename Protocol_>
folly::exception_wrapper LucidaServiceAsyncClient::recv_wrapped_inferT(Protocol_* prot, std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return state.exceptionWrapper();
  }
  prot->setInput(state.buf());
  auto guard = folly::makeGuard([&] {prot->setInput(nullptr);});
  apache::thrift::ContextStack* ctx = state.ctx();
  std::string fname;
  int32_t protoSeqId = 0;
  apache::thrift::MessageType mtype;
  ctx->preRead();
  folly::exception_wrapper interior_ew;
  auto caught_ew = folly::try_and_catch<std::exception, apache::thrift::TException, apache::thrift::protocol::TProtocolException>([&]() {
    prot->readMessageBegin(fname, mtype, protoSeqId);
    if (mtype == apache::thrift::T_EXCEPTION) {
      apache::thrift::TApplicationException x;
      x.read(prot);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(x);
      return; // from try_and_catch
    }
    if (mtype != apache::thrift::T_REPLY) {
      prot->skip(apache::thrift::protocol::T_STRUCT);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::INVALID_MESSAGE_TYPE);
      return; // from try_and_catch
    }
    if (fname.compare("infer") != 0) {
      prot->skip(apache::thrift::protocol::T_STRUCT);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::WRONG_METHOD_NAME);
      return; // from try_and_catch
    }
    ::apache::thrift::SerializedMessage smsg;
    smsg.protocolType = prot->protocolType();
    smsg.buffer = state.buf();
    ctx->onReadData(smsg);
    LucidaService_infer_presult result;
    result.get<0>().value = &_return;
    result.read(prot);
    prot->readMessageEnd();
    ctx->postRead(state.header(), state.buf()->length());
    if (result.getIsSet(0)) {
      // _return pointer has been filled
      return; // from try_and_catch
    }
    else {
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::MISSING_RESULT, "failed: unknown result");
      return; // from try_and_catch
    }
  }
  );
  auto ew = interior_ew ? std::move(interior_ew) : std::move(caught_ew);
  if (ew) {
    ctx->handlerErrorWrapped(ew);
  }
  return ew;
}

template <typename Protocol_>
void LucidaServiceAsyncClient::recv_inferT(Protocol_* prot, std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_inferT(prot, _return, state);
  if (ew) {
    ew.throwException();
  }
}

} // cpp2
namespace apache { namespace thrift {

}} // apache::thrift