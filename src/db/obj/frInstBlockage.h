/* Authors: Lutong Wang and Bangqi Xu */
/*
 * Copyright (c) 2019, The Regents of the University of California
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the University nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE REGENTS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _FR_INSTBLOCKAGE_H_
#define _FR_INSTBLOCKAGE_H_

#include <memory>
#include "frBaseTypes.h"
#include "db/obj/frBlockObject.h"
#include "db/obj/frBlockage.h"

namespace fr {
  class frInst;
  class frInstBlockage: public frBlockObject {
  public:
    // constructors
    frInstBlockage(): frBlockObject(), inst(nullptr), blockage(nullptr) {}
    // getters
    frInst* getInst() const {
      return inst;
    }
    frBlockage* getBlockage() const {
      return blockage;
    }
    // setters
    void addToInst(frInst* in) {
      inst = in;
    }
    // do not call from outside
    void addBlockage(frBlockage* in) {
      blockage = in;
    }
    // others
    frBlockObjectEnum typeId() const override {
      return frcInstBlockage;
    }
  protected:
    frInst*     inst;
    frBlockage* blockage;
  };
}

#endif
