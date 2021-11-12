// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright 2021 yuzu Emulator Project
// Copyright 2014 The Android Open Source Project
// Parts of this implementation were base on:
// https://cs.android.com/android/platform/superproject/+/android-5.1.1_r38:frameworks/native/include/gui/BufferSlot.h

#pragma once

#include <memory>

#include "common/common_types.h"
#include "core/hle/service/nvflinger/ui/fence.h"

namespace android {

class GraphicBuffer;

enum class BufferState : u32 {
    Free = 0,
    Dequeued = 1,
    Queued = 2,
    Acquired = 3,
};

struct BufferSlot final {
    constexpr BufferSlot() = default;

    std::shared_ptr<GraphicBuffer> graphic_buffer;
    BufferState buffer_state{BufferState::Free};
    bool request_buffer_called{};
    u64 frame_number{};
    Fence fence;
    bool acquire_called{};
    bool needs_cleanup_on_release{};
    bool attached_by_consumer{};
    bool is_preallocated{};
};

} // namespace android
