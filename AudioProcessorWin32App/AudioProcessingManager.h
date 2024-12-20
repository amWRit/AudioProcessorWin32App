#pragma once
#ifndef AUDIO_PROCESSOR_MANAGER_H
#define AUDIO_PROCESSOR_MANAGER_H

#include <memory>
#include <string>
#include "AudioFileHandler.h" // Include the necessary header for AudioFileHandler
#include "EnumClass.h"
#include "AudioProcessingStrategyFactory.h"

class AudioProcessingManager {
    public:
        void setFileHandler(const std::shared_ptr<AudioFileHandler>& handler);
        void setProcessedSignal(const std::vector<double>& outputSignal);
        const std::vector<double> getProcessedSignal();
        // Loads an audio file and returns a shared pointer to the AudioFileHandler.
        std::shared_ptr<AudioFileHandler> loadAudioFile(const std::string& filePath);

        bool processAudio(const AudioProcessingStrategyFactory::ParamMap& params);

        bool reverseAudio();
        bool reverbAudio(double delayTime, double decayFactor);
        bool changeSpeed(double speedFactor);
        bool changeVolume(double volumeFactor);
        bool extractAudio(InstrumentType instrumentType);

        StrategyType strategyType;

    private:
        std::shared_ptr<AudioFileHandler> fileHandler; // Store the audio file handler
        std::vector<double> processedSignal;
        
};

#endif // AUDIO_PROCESSOR_MANAGER_H
