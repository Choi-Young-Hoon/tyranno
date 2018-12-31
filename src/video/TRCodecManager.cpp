#include "TRCodecManager.hpp"

TRCodecManager::TRCodecManager() 
{}

TRCodecManager::~TRCodecManager()
{}


TRCodec* TRCodecManager::CreateCodec(CODEC_TYPE codec_type, TRCodecID& codec_id, TRCodecParameters& codec_parameters, TRError* error) {
    TRCodec* ret_codec = NULL;

    switch (codec_type) {
    case CODEC_TYPE::DECODE_CODEC:
        ret_codec = CreateDecodeCodec(error);
        break; 
    case CODEC_TYPE::ENCODE_CODEC:
        ret_codec = CreateEncodeCodec(error);
        break;
    default:
        error->SetErrorValue(ERROR_DEFINE::UNKNOWN_CODEC_TYPE, "Unknown codec type");
        return NULL;
    }
    
    if (error->GetErrorCode() != ERROR_DEFINE::SUCCESS) {
        if (error->GetErrorCode() == ERROR_DEFINE::MEMORY_ALLOC_FAILED) {
            delete ret_codec;
        }
        return NULL;
    }

    ret_codec->InitializeCodec(codec_id, codec_parameters, error);
    if (error->GetErrorCode() != ERROR_DEFINE::SUCCESS) {
        delete ret_codec;
        return NULL;
    }

    return ret_codec;
}

TRCodec* TRCodecManager::CreateCodec(CODEC_TYPE codec_type, TRVideo& video, TRError* error) {
    TRCodecID codec_id = video.GetCodecID();
    TRCodecParameters codec_parameter = video.GetCodecParameters();
    
    return CreateCodec(codec_type, codec_id, codec_parameter, error);
}


TRCodec* TRCodecManager::CreateEncodeCodec(TRError* error) {
    TRCodec* ret_codec = new TREncodeCodec();
    if (ret_codec == NULL) {
        error->SetErrorValue(ERROR_DEFINE::MEMORY_ALLOC_FAILED, "Codec memory alloc is NULL");
        return NULL;
    }

    error->SetErrorCode(ERROR_DEFINE::SUCCESS);
    return ret_codec;
}

TRCodec* TRCodecManager::CreateDecodeCodec(TRError* error) {
    TRCodec* ret_codec = new TRDecodeCodec();
    if (ret_codec == NULL) {
        error->SetErrorValue(ERROR_DEFINE::MEMORY_ALLOC_FAILED, "Codec memory alloc is NULL");
        return NULL;
    }

    error->SetErrorCode(ERROR_DEFINE::SUCCESS);
    return ret_codec;
}