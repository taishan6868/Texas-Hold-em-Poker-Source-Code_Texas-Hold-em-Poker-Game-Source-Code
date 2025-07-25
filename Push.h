// **********************************************************************
// This file was generated by a TARS parser!
// TARS version 2.4.7.
// **********************************************************************

#ifndef __PUSH_H_
#define __PUSH_H_

#include <map>
#include <string>
#include <vector>
#include "tup/Tars.h"
#include "tup/TarsJson.h"
using namespace std;
#include "JFGameCommProto.h"
#include "servant/ServantProxy.h"
#include "servant/Servant.h"


namespace ai
{

    /* callback of async proxy for client */
    class PushPrxCallback: public tars::ServantProxyCallback
    {
    public:
        virtual ~PushPrxCallback(){}
        virtual void callback_doPush(tars::Int32 ret)
        { throw std::runtime_error("callback_doPush() override incorrect."); }
        virtual void callback_doPush_exception(tars::Int32 ret)
        { throw std::runtime_error("callback_doPush_exception() override incorrect."); }

    public:
        virtual const map<std::string, std::string> & getResponseContext() const
        {
            CallbackThreadData * pCbtd = CallbackThreadData::getData();
            assert(pCbtd != NULL);

            if(!pCbtd->getContextValid())
            {
                throw TC_Exception("cann't get response context");
            }
            return pCbtd->getResponseContext();
        }

    public:
        virtual int onDispatch(tars::ReqMessagePtr msg)
        {
            static ::std::string __Push_all[]=
            {
                "doPush"
            };
            pair<string*, string*> r = equal_range(__Push_all, __Push_all+1, string(msg->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __Push_all)
            {
                case 0:
                {
                    if (msg->response->iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_doPush_exception(msg->response->iRet);

                        return msg->response->iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response->sBuffer);
                    tars::Int32 _ret;
                    _is.read(_ret, 0, true);

                    CallbackThreadData * pCbtd = CallbackThreadData::getData();
                    assert(pCbtd != NULL);

                    pCbtd->setResponseContext(msg->response->context);

                    callback_doPush(_ret);

                    pCbtd->delResponseContext();

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    };
    typedef tars::TC_AutoPtr<PushPrxCallback> PushPrxCallbackPtr;

    /* callback of coroutine async proxy for client */
    class PushCoroPrxCallback: public PushPrxCallback
    {
    public:
        virtual ~PushCoroPrxCallback(){}
    public:
        virtual const map<std::string, std::string> & getResponseContext() const { return _mRspContext; }

        virtual void setResponseContext(const map<std::string, std::string> &mContext) { _mRspContext = mContext; }

    public:
        int onDispatch(tars::ReqMessagePtr msg)
        {
            static ::std::string __Push_all[]=
            {
                "doPush"
            };

            pair<string*, string*> r = equal_range(__Push_all, __Push_all+1, string(msg->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __Push_all)
            {
                case 0:
                {
                    if (msg->response->iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_doPush_exception(msg->response->iRet);

                        return msg->response->iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response->sBuffer);
                    try
                    {
                        tars::Int32 _ret;
                        _is.read(_ret, 0, true);

                        setResponseContext(msg->response->context);

                        callback_doPush(_ret);

                    }
                    catch(std::exception &ex)
                    {
                        callback_doPush_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_doPush_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    protected:
        map<std::string, std::string> _mRspContext;
    };
    typedef tars::TC_AutoPtr<PushCoroPrxCallback> PushCoroPrxCallbackPtr;

    /* proxy for client */
    class PushProxy : public tars::ServantProxy
    {
    public:
        typedef map<string, string> TARS_CONTEXT;
        tars::Int32 doPush(tars::Int64 uin,const JFGamecomm::TPackage & tPack,const map<string, string> &context = TARS_CONTEXT(),map<string, string> * pResponseContext = NULL)
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(uin, 1);
            _os.write(tPack, 2);
            std::map<string, string> _mStatus;
            shared_ptr<tars::ResponsePacket> rep = tars_invoke(tars::TARSNORMAL,"doPush", _os, context, _mStatus);
            if(pResponseContext)
            {
                pResponseContext->swap(rep->context);
            }

            tars::TarsInputStream<tars::BufferReader> _is;
            _is.setBuffer(rep->sBuffer);
            tars::Int32 _ret;
            _is.read(_ret, 0, true);
            return _ret;
        }

        void async_doPush(PushPrxCallbackPtr callback,tars::Int64 uin,const JFGamecomm::TPackage &tPack,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(uin, 1);
            _os.write(tPack, 2);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"doPush", _os, context, _mStatus, callback);
        }
        
        void coro_doPush(PushCoroPrxCallbackPtr callback,tars::Int64 uin,const JFGamecomm::TPackage &tPack,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(uin, 1);
            _os.write(tPack, 2);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"doPush", _os, context, _mStatus, callback, true);
        }

        PushProxy* tars_hash(int64_t key)
        {
            return (PushProxy*)ServantProxy::tars_hash(key);
        }

        PushProxy* tars_consistent_hash(int64_t key)
        {
            return (PushProxy*)ServantProxy::tars_consistent_hash(key);
        }

        PushProxy* tars_set_timeout(int msecond)
        {
            return (PushProxy*)ServantProxy::tars_set_timeout(msecond);
        }

        static const char* tars_prxname() { return "PushProxy"; }
    };
    typedef tars::TC_AutoPtr<PushProxy> PushPrx;

    /* servant for server */
    class Push : public tars::Servant
    {
    public:
        virtual ~Push(){}
        virtual tars::Int32 doPush(tars::Int64 uin,const JFGamecomm::TPackage & tPack,tars::TarsCurrentPtr current) = 0;
        static void async_response_doPush(tars::TarsCurrentPtr current, tars::Int32 _ret)
        {
            if (current->getRequestVersion() == TUPVERSION )
            {
                UniAttribute<tars::BufferWriterVector, tars::BufferReader>  tarsAttr;
                tarsAttr.setVersion(current->getRequestVersion());
                tarsAttr.put("", _ret);
                tarsAttr.put("tars_ret", _ret);

                vector<char> sTupResponseBuffer;
                tarsAttr.encode(sTupResponseBuffer);
                current->sendResponse(tars::TARSSERVERSUCCESS, sTupResponseBuffer);
            }
            else if (current->getRequestVersion() == JSONVERSION)
            {
                tars::JsonValueObjPtr _p = new tars::JsonValueObj();
                _p->value["tars_ret"] = tars::JsonOutput::writeJson(_ret);
                vector<char> sJsonResponseBuffer;
                tars::TC_Json::writeValue(_p, sJsonResponseBuffer);
                current->sendResponse(tars::TARSSERVERSUCCESS, sJsonResponseBuffer);
            }
            else
            {
                tars::TarsOutputStream<tars::BufferWriterVector> _os;
                _os.write(_ret, 0);

                current->sendResponse(tars::TARSSERVERSUCCESS, _os.getByteBuffer());
            }
        }

    public:
        int onDispatch(tars::TarsCurrentPtr _current, vector<char> &_sResponseBuffer)
        {
            static ::std::string __ai__Push_all[]=
            {
                "doPush"
            };

            pair<string*, string*> r = equal_range(__ai__Push_all, __ai__Push_all+1, _current->getFuncName());
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __ai__Push_all)
            {
                case 0:
                {
                    tars::TarsInputStream<tars::BufferReader> _is;
                    _is.setBuffer(_current->getRequestBuffer());
                    tars::Int64 uin;
                    JFGamecomm::TPackage tPack;
                    if (_current->getRequestVersion() == TUPVERSION)
                    {
                        UniAttribute<tars::BufferWriterVector, tars::BufferReader>  tarsAttr;
                        tarsAttr.setVersion(_current->getRequestVersion());
                        tarsAttr.decode(_current->getRequestBuffer());
                        tarsAttr.get("uin", uin);
                        tarsAttr.get("tPack", tPack);
                    }
                    else if (_current->getRequestVersion() == JSONVERSION)
                    {
                        tars::JsonValueObjPtr _jsonPtr = tars::JsonValueObjPtr::dynamicCast(tars::TC_Json::getValue(_current->getRequestBuffer()));
                        tars::JsonInput::readJson(uin, _jsonPtr->value["uin"], true);
                        tars::JsonInput::readJson(tPack, _jsonPtr->value["tPack"], true);
                    }
                    else
                    {
                        _is.read(uin, 1, true);
                        _is.read(tPack, 2, true);
                    }
                    tars::Int32 _ret = doPush(uin,tPack, _current);
                    if(_current->isResponse())
                    {
                        if (_current->getRequestVersion() == TUPVERSION)
                        {
                            UniAttribute<tars::BufferWriterVector, tars::BufferReader>  tarsAttr;
                            tarsAttr.setVersion(_current->getRequestVersion());
                            tarsAttr.put("", _ret);
                            tarsAttr.put("tars_ret", _ret);
                            tarsAttr.encode(_sResponseBuffer);
                        }
                        else if (_current->getRequestVersion() == JSONVERSION)
                        {
                            tars::JsonValueObjPtr _p = new tars::JsonValueObj();
                            _p->value["tars_ret"] = tars::JsonOutput::writeJson(_ret);
                            tars::TC_Json::writeValue(_p, _sResponseBuffer);
                        }
                        else
                        {
                            tars::TarsOutputStream<tars::BufferWriterVector> _os;
                            _os.write(_ret, 0);
                            _os.swap(_sResponseBuffer);
                        }
                    }
                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }
    };


}



#endif
