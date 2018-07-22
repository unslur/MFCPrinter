

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for MFCPrinter.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __MFCPrinteridl_h__
#define __MFCPrinteridl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DMFCPrinter_FWD_DEFINED__
#define ___DMFCPrinter_FWD_DEFINED__
typedef interface _DMFCPrinter _DMFCPrinter;

#endif 	/* ___DMFCPrinter_FWD_DEFINED__ */


#ifndef ___DMFCPrinterEvents_FWD_DEFINED__
#define ___DMFCPrinterEvents_FWD_DEFINED__
typedef interface _DMFCPrinterEvents _DMFCPrinterEvents;

#endif 	/* ___DMFCPrinterEvents_FWD_DEFINED__ */


#ifndef __MFCPrinter_FWD_DEFINED__
#define __MFCPrinter_FWD_DEFINED__

#ifdef __cplusplus
typedef class MFCPrinter MFCPrinter;
#else
typedef struct MFCPrinter MFCPrinter;
#endif /* __cplusplus */

#endif 	/* __MFCPrinter_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_MFCPrinter_0000_0000 */
/* [local] */ 

#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(pop)
#pragma warning(pop)
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_MFCPrinter_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_MFCPrinter_0000_0000_v0_0_s_ifspec;


#ifndef __MFCPrinterLib_LIBRARY_DEFINED__
#define __MFCPrinterLib_LIBRARY_DEFINED__

/* library MFCPrinterLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_MFCPrinterLib;

#ifndef ___DMFCPrinter_DISPINTERFACE_DEFINED__
#define ___DMFCPrinter_DISPINTERFACE_DEFINED__

/* dispinterface _DMFCPrinter */
/* [uuid] */ 


EXTERN_C const IID DIID__DMFCPrinter;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("91e463b2-be4b-4c9e-a97f-ca88b6423734")
    _DMFCPrinter : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DMFCPrinterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DMFCPrinter * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DMFCPrinter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DMFCPrinter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DMFCPrinter * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DMFCPrinter * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DMFCPrinter * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DMFCPrinter * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DMFCPrinterVtbl;

    interface _DMFCPrinter
    {
        CONST_VTBL struct _DMFCPrinterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DMFCPrinter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DMFCPrinter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DMFCPrinter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DMFCPrinter_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DMFCPrinter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DMFCPrinter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DMFCPrinter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DMFCPrinter_DISPINTERFACE_DEFINED__ */


#ifndef ___DMFCPrinterEvents_DISPINTERFACE_DEFINED__
#define ___DMFCPrinterEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DMFCPrinterEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DMFCPrinterEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("49c222ac-435b-47b6-98ea-f78400caad63")
    _DMFCPrinterEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DMFCPrinterEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DMFCPrinterEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DMFCPrinterEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DMFCPrinterEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DMFCPrinterEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DMFCPrinterEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DMFCPrinterEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DMFCPrinterEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DMFCPrinterEventsVtbl;

    interface _DMFCPrinterEvents
    {
        CONST_VTBL struct _DMFCPrinterEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DMFCPrinterEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DMFCPrinterEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DMFCPrinterEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DMFCPrinterEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DMFCPrinterEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DMFCPrinterEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DMFCPrinterEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DMFCPrinterEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MFCPrinter;

#ifdef __cplusplus

class DECLSPEC_UUID("56cd549d-36e7-4b3e-a417-01e81140ee4d")
MFCPrinter;
#endif
#endif /* __MFCPrinterLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


