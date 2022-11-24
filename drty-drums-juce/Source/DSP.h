/* ------------------------------------------------------------
name: "main"
Code generated with Faust 2.50.6 (https://faust.grame.fr)
Compilation options: -a cApi.h -lang cpp -i -es 1 -mcd 16 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

#include <cmath>
#include <cstring>

/************************** BEGIN MapUI.h ******************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ***********************************************************************/

#ifndef FAUST_MAPUI_H
#define FAUST_MAPUI_H

#include <vector>
#include <map>
#include <string>
#include <stdio.h>

/************************** BEGIN UI.h *****************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ********************************************************************/

#ifndef __UI_H__
#define __UI_H__

/************************************************************************
 ************************************************************************
    FAUST compiler
    Copyright (C) 2003-2018 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 ************************************************************************
 ************************************************************************/

#ifndef __export__
#define __export__

#define FAUSTVERSION "2.50.6"

// Use FAUST_API for code that is part of the external API but is also compiled in faust and libfaust
// Use LIBFAUST_API for code that is compiled in faust and libfaust

#ifdef _WIN32
    #pragma warning (disable: 4251)
    #ifdef FAUST_EXE
        #define FAUST_API
        #define LIBFAUST_API
    #elif FAUST_LIB
        #define FAUST_API __declspec(dllexport)
        #define LIBFAUST_API __declspec(dllexport)
    #else
        #define FAUST_API
        #define LIBFAUST_API 
    #endif
#else
    #ifdef FAUST_EXE
        #define FAUST_API
        #define LIBFAUST_API
    #else
        #define FAUST_API __attribute__((visibility("default")))
        #define LIBFAUST_API __attribute__((visibility("default")))
    #endif
#endif

#endif

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust DSP User Interface
 * User Interface as expected by the buildUserInterface() method of a DSP.
 * This abstract class contains only the method that the Faust compiler can
 * generate to describe a DSP user interface.
 ******************************************************************************/

struct Soundfile;

template <typename REAL>
struct FAUST_API UIReal {
    
    UIReal() {}
    virtual ~UIReal() {}
    
    // -- widget's layouts
    
    virtual void openTabBox(const char* label) = 0;
    virtual void openHorizontalBox(const char* label) = 0;
    virtual void openVerticalBox(const char* label) = 0;
    virtual void closeBox() = 0;
    
    // -- active widgets
    
    virtual void addButton(const char* label, REAL* zone) = 0;
    virtual void addCheckButton(const char* label, REAL* zone) = 0;
    virtual void addVerticalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
    virtual void addHorizontalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
    virtual void addNumEntry(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step) = 0;
    
    // -- passive widgets
    
    virtual void addHorizontalBargraph(const char* label, REAL* zone, REAL min, REAL max) = 0;
    virtual void addVerticalBargraph(const char* label, REAL* zone, REAL min, REAL max) = 0;
    
    // -- soundfiles
    
    virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;
    
    // -- metadata declarations
    
    virtual void declare(REAL* zone, const char* key, const char* val) {}
    
    // To be used by LLVM client
    virtual int sizeOfFAUSTFLOAT() { return sizeof(FAUSTFLOAT); }
};

struct FAUST_API UI : public UIReal<FAUSTFLOAT> {
    UI() {}
    virtual ~UI() {}
};

#endif
/**************************  END  UI.h **************************/
/************************** BEGIN PathBuilder.h **************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __PathBuilder__
#define __PathBuilder__

#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <regex>


/*******************************************************************************
 * PathBuilder : Faust User Interface
 * Helper class to build complete hierarchical path for UI items.
 ******************************************************************************/

class FAUST_API PathBuilder {

    protected:
    
        std::vector<std::string> fControlsLevel;
        std::vector<std::string> fFullPaths;
        std::map<std::string, std::string> fFull2Short;  // filled by computeShortNames()
    
        /**
         * @brief check if a character is acceptable for an ID
         *
         * @param c
         * @return true is the character is acceptable for an ID
         */
        bool isIDChar(char c) const
        {
            return ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')) || ((c >= '0') && (c <= '9'));
        }
    
        /**
         * @brief remove all "/0x00" parts
         *
         * @param src
         * @return modified string
         */
        std::string remove0x00(const std::string& src) const
        {
            return std::regex_replace(src, std::regex("/0x00"), "");
        }
    
        /**
         * @brief replace all non ID char with '_' (one '_' may replace several non ID char)
         *
         * @param src
         * @return modified string
         */
        std::string str2ID(const std::string& src) const
        {
            std::string dst;
            bool need_underscore = false;
            for (char c : src) {
                if (isIDChar(c) || (c == '/')) {
                    if (need_underscore) {
                        dst.push_back('_');
                        need_underscore = false;
                    }
                    dst.push_back(c);
                } else {
                    need_underscore = true;
                }
            }
            return dst;
        }
    
        /**
         * @brief Keep only the last n slash-parts
         *
         * @param src
         * @param n : 1 indicates the last slash-part
         * @return modified string
         */
        std::string cut(const std::string& src, int n) const
        {
            std::string rdst;
            for (int i = int(src.length())-1; i >= 0; i--) {
                char c = src[i];
                if (c != '/') {
                    rdst.push_back(c);
                } else if (n == 1) {
                    std::string dst;
                    for (int j = int(rdst.length())-1; j >= 0; j--) {
                        dst.push_back(rdst[j]);
                    }
                    return dst;
                } else {
                    n--;
                    rdst.push_back(c);
                }
            }
            return src;
        }
    
        void addFullPath(const std::string& label) { fFullPaths.push_back(buildPath(label)); }
    
        /**
         * @brief Compute the mapping between full path and short names
         */
        void computeShortNames()
        {
            std::vector<std::string>           uniquePaths;  // all full paths transformed but made unique with a prefix
            std::map<std::string, std::string> unique2full;  // all full paths transformed but made unique with a prefix
            char num_buffer[16];
            int pnum = 0;
        
            for (const auto& s : fFullPaths) {
                sprintf(num_buffer, "%d", pnum++);
                std::string u = "/P" + std::string(num_buffer) + str2ID(remove0x00(s));
                uniquePaths.push_back(u);
                unique2full[u] = s;  // remember the full path associated to a unique path
            }
        
            std::map<std::string, int> uniquePath2level;                // map path to level
            for (const auto& s : uniquePaths) uniquePath2level[s] = 1;   // we init all levels to 1
            bool have_collisions = true;
        
            while (have_collisions) {
                // compute collision list
                std::set<std::string>              collisionSet;
                std::map<std::string, std::string> short2full;
                have_collisions = false;
                for (const auto& it : uniquePath2level) {
                    std::string u = it.first;
                    int n = it.second;
                    std::string shortName = cut(u, n);
                    auto p = short2full.find(shortName);
                    if (p == short2full.end()) {
                        // no collision
                        short2full[shortName] = u;
                    } else {
                        // we have a collision, add the two paths to the collision set
                        have_collisions = true;
                        collisionSet.insert(u);
                        collisionSet.insert(p->second);
                    }
                }
                for (const auto& s : collisionSet) uniquePath2level[s]++;  // increase level of colliding path
            }
        
            for (const auto& it : uniquePath2level) {
                std::string u = it.first;
                int n = it.second;
                std::string shortName = replaceCharList(cut(u, n), {'/'}, '_');
                fFull2Short[unique2full[u]] = shortName;
            }
        }
    
        std::string replaceCharList(const std::string& str, const std::vector<char>& ch1, char ch2)
        {
            auto beg = ch1.begin();
            auto end = ch1.end();
            std::string res = str;
            for (size_t i = 0; i < str.length(); ++i) {
                if (std::find(beg, end, str[i]) != end) res[i] = ch2;
            }
            return res;
        }
     
    public:
    
        PathBuilder() {}
        virtual ~PathBuilder() {}
    
        // Return true for the first level of groups
        bool pushLabel(const std::string& label) { fControlsLevel.push_back(label); return fControlsLevel.size() == 1;}
    
        // Return true for the last level of groups
        bool popLabel() { fControlsLevel.pop_back(); return fControlsLevel.size() == 0; }
    
        std::string buildPath(const std::string& label)
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res = res + fControlsLevel[i] + "/";
            }
            res += label;
            return replaceCharList(res, {' ', '#', '*', ',', '?', '[', ']', '{', '}', '(', ')'}, '_');
        }
    
};

#endif  // __PathBuilder__
/**************************  END  PathBuilder.h **************************/

/*******************************************************************************
 * MapUI : Faust User Interface.
 *
 * This class creates:
 * - a map of 'labels' and zones for each UI item.
 * - a map of unique 'shortname' (built so that they never collide) and zones for each UI item
 * - a map of complete hierarchical 'paths' and zones for each UI item
 *
 * Simple 'labels', 'shortname' and complete 'paths' (to fully discriminate between possible same
 * 'labels' at different location in the UI hierachy) can be used to access a given parameter.
 ******************************************************************************/

class FAUST_API MapUI : public UI, public PathBuilder
{
    
    protected:
    
        // Label zone map
        std::map<std::string, FAUSTFLOAT*> fLabelZoneMap;
    
        // Shortname zone map
        std::map<std::string, FAUSTFLOAT*> fShortnameZoneMap;
    
        // Full path map
        std::map<std::string, FAUSTFLOAT*> fPathZoneMap;
    
        void addZoneLabel(const std::string& label, FAUSTFLOAT* zone)
        {
            std::string path = buildPath(label);
            fFullPaths.push_back(path);
            fPathZoneMap[path] = zone;
            fLabelZoneMap[label] = zone;
        }
    
    public:
        
        MapUI() {}
        virtual ~MapUI() {}
        
        // -- widget's layouts
        void openTabBox(const char* label)
        {
            pushLabel(label);
        }
        void openHorizontalBox(const char* label)
        {
            pushLabel(label);
        }
        void openVerticalBox(const char* label)
        {
            pushLabel(label);
        }
        void closeBox()
        {
            if (popLabel()) {
                // Shortnames can be computed when all fullnames are known
                computeShortNames();
                // Fill 'shortname' map
                for (const auto& it : fFullPaths) {
                    fShortnameZoneMap[fFull2Short[it]] = fPathZoneMap[it];
                }
            }
        }
        
        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addZoneLabel(label, zone);
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addZoneLabel(label, zone);
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            addZoneLabel(label, zone);
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            addZoneLabel(label, zone);
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            addZoneLabel(label, zone);
        }
        
        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            addZoneLabel(label, zone);
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            addZoneLabel(label, zone);
        }
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
        
        // -- metadata declarations
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {}
    
        //-------------------------------------------------------------------------------
        // Public API
        //-------------------------------------------------------------------------------
    
        /**
         * Set the param value.
         *
         * @param str - the UI parameter label/shortname/path
         * @param value - the UI parameter value
         *
         */
        void setParamValue(const std::string& str, FAUSTFLOAT value)
        {
            if (fPathZoneMap.find(str) != fPathZoneMap.end()) {
                *fPathZoneMap[str] = value;
            } else if (fShortnameZoneMap.find(str) != fShortnameZoneMap.end()) {
                *fShortnameZoneMap[str] = value;
            } else if (fLabelZoneMap.find(str) != fLabelZoneMap.end()) {
                *fLabelZoneMap[str] = value;
            } else {
                fprintf(stderr, "ERROR : setParamValue '%s' not found\n", str.c_str());
            }
        }
        
        /**
         * Return the param value.
         *
         * @param str - the UI parameter label/shortname/path
         *
         * @return the param value.
         */
        FAUSTFLOAT getParamValue(const std::string& str)
        {
            if (fPathZoneMap.find(str) != fPathZoneMap.end()) {
                return *fPathZoneMap[str];
            } else if (fShortnameZoneMap.find(str) != fShortnameZoneMap.end()) {
                return *fShortnameZoneMap[str];
            } else if (fLabelZoneMap.find(str) != fLabelZoneMap.end()) {
                return *fLabelZoneMap[str];
            } else {
                fprintf(stderr, "ERROR : getParamValue '%s' not found\n", str.c_str());
                return 0;
            }
        }
    
        // map access 
        std::map<std::string, FAUSTFLOAT*>& getFullpathMap() { return fPathZoneMap; }
        std::map<std::string, FAUSTFLOAT*>& getShortnameMap() { return fShortnameZoneMap; }
        std::map<std::string, FAUSTFLOAT*>& getLabelMap() { return fLabelZoneMap; }
            
        /**
         * Return the number of parameters in the UI.
         *
         * @return the number of parameters
         */
        int getParamsCount() { return int(fPathZoneMap.size()); }
        
        /**
         * Return the param path.
         *
         * @param index - the UI parameter index
         *
         * @return the param path
         */
        std::string getParamAddress(int index)
        {
            if (index < 0 || index > int(fPathZoneMap.size())) {
                return "";
            } else {
                auto it = fPathZoneMap.begin();
                while (index-- > 0 && it++ != fPathZoneMap.end()) {}
                return it->first;
            }
        }
        
        const char* getParamAddress1(int index)
        {
            if (index < 0 || index > int(fPathZoneMap.size())) {
                return nullptr;
            } else {
                auto it = fPathZoneMap.begin();
                while (index-- > 0 && it++ != fPathZoneMap.end()) {}
                return it->first.c_str();
            }
        }
    
        /**
         * Return the param shortname.
         *
         * @param index - the UI parameter index
         *
         * @return the param shortname
         */
        std::string getParamShortname(int index)
        {
            if (index < 0 || index > int(fShortnameZoneMap.size())) {
                return "";
            } else {
                auto it = fShortnameZoneMap.begin();
                while (index-- > 0 && it++ != fShortnameZoneMap.end()) {}
                return it->first;
            }
        }
        
        const char* getParamShortname1(int index)
        {
            if (index < 0 || index > int(fShortnameZoneMap.size())) {
                return nullptr;
            } else {
                auto it = fShortnameZoneMap.begin();
                while (index-- > 0 && it++ != fShortnameZoneMap.end()) {}
                return it->first.c_str();
            }
        }
    
        /**
         * Return the param label.
         *
         * @param index - the UI parameter index
         *
         * @return the param label
         */
        std::string getParamLabel(int index)
        {
            if (index < 0 || index > int(fLabelZoneMap.size())) {
                return "";
            } else {
                auto it = fLabelZoneMap.begin();
                while (index-- > 0 && it++ != fLabelZoneMap.end()) {}
                return it->first;
            }
        }
        
        const char* getParamLabel1(int index)
        {
            if (index < 0 || index > int(fLabelZoneMap.size())) {
                return nullptr;
            } else {
                auto it = fLabelZoneMap.begin();
                while (index-- > 0 && it++ != fLabelZoneMap.end()) {}
                return it->first.c_str();
            }
        }
    
        /**
         * Return the param path.
         *
         * @param zone - the UI parameter memory zone
         *
         * @return the param path
         */
        std::string getParamAddress(FAUSTFLOAT* zone)
        {
            for (const auto& it : fPathZoneMap) {
                if (it.second == zone) return it.first;
            }
            return "";
        }
    
        /**
         * Return the param memory zone.
         *
         * @param zone - the UI parameter label/shortname/path
         *
         * @return the param path
         */
        FAUSTFLOAT* getParamZone(const std::string& str)
        {
            if (fPathZoneMap.find(str) != fPathZoneMap.end()) {
                return fPathZoneMap[str];
            } else if (fShortnameZoneMap.find(str) != fShortnameZoneMap.end()) {
                return fShortnameZoneMap[str];
            } else if (fLabelZoneMap.find(str) != fLabelZoneMap.end()) {
                return fLabelZoneMap[str];
            }
            return nullptr;
        }
    
        /**
         * Return the param memory zone.
         *
         * @param zone - the UI parameter index
         *
         * @return the param path
         */
        FAUSTFLOAT* getParamZone(int index)
        {
            if (index < 0 || index > int(fPathZoneMap.size())) {
                return nullptr;
            } else {
                auto it = fPathZoneMap.begin();
                while (index-- > 0 && it++ != fPathZoneMap.end()) {}
                return it->second;
            }
        }
    
        static bool endsWith(const std::string& str, const std::string& end)
        {
            size_t l1 = str.length();
            size_t l2 = end.length();
            return (l1 >= l2) && (0 == str.compare(l1 - l2, l2, end));
        }
    
};

#endif // FAUST_MAPUI_H
/**************************  END  MapUI.h **************************/
/************************** BEGIN meta.h *******************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __meta__
#define __meta__


/**
 The base class of Meta handler to be used in dsp::metadata(Meta* m) method to retrieve (key, value) metadata.
 */
struct FAUST_API Meta {
    virtual ~Meta() {}
    virtual void declare(const char* key, const char* value) = 0;
};

#endif
/**************************  END  meta.h **************************/
/************************** BEGIN dsp.h ********************************
 FAUST Architecture File
 Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp__
#define __dsp__

#include <string>
#include <vector>


#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

struct FAUST_API UI;
struct FAUST_API Meta;

/**
 * DSP memory manager.
 */

struct FAUST_API dsp_memory_manager {
    
    virtual ~dsp_memory_manager() {}
    
    /**
     * Inform the Memory Manager with the number of expected memory zones.
     * @param count - the number of expected memory zones
     */
    virtual void begin(size_t count) {}
    
    /**
     * Give the Memory Manager information on a given memory zone.
     * @param size - the size in bytes of the memory zone
     * @param reads - the number of Read access to the zone used to compute one frame
     * @param writes - the number of Write access to the zone used to compute one frame
     */
    virtual void info(size_t size, size_t reads, size_t writes) {}
    
    /**
     * Inform the Memory Manager that all memory zones have been described,
     * to possibly start a 'compute the best allocation strategy' step.
     */
    virtual void end() {}
    
    /**
     * Allocate a memory zone.
     * @param size - the memory zone size in bytes
     */
    virtual void* allocate(size_t size) = 0;
    
    /**
     * Destroy a memory zone.
     * @param ptr - the memory zone pointer to be deallocated
     */
    virtual void destroy(void* ptr) = 0;
    
};

/**
* Signal processor definition.
*/

class FAUST_API dsp {

    public:

        dsp() {}
        virtual ~dsp() {}

        /* Return instance number of audio inputs */
        virtual int getNumInputs() = 0;
    
        /* Return instance number of audio outputs */
        virtual int getNumOutputs() = 0;
    
        /**
         * Trigger the ui_interface parameter with instance specific calls
         * to 'openTabBox', 'addButton', 'addVerticalSlider'... in order to build the UI.
         *
         * @param ui_interface - the user interface builder
         */
        virtual void buildUserInterface(UI* ui_interface) = 0;
    
        /* Return the sample rate currently used by the instance */
        virtual int getSampleRate() = 0;
    
        /**
         * Global init, calls the following methods:
         * - static class 'classInit': static tables initialization
         * - 'instanceInit': constants and instance state initialization
         *
         * @param sample_rate - the sampling rate in Hz
         */
        virtual void init(int sample_rate) = 0;

        /**
         * Init instance state
         *
         * @param sample_rate - the sampling rate in Hz
         */
        virtual void instanceInit(int sample_rate) = 0;
    
        /**
         * Init instance constant state
         *
         * @param sample_rate - the sampling rate in Hz
         */
        virtual void instanceConstants(int sample_rate) = 0;
    
        /* Init default control parameters values */
        virtual void instanceResetUserInterface() = 0;
    
        /* Init instance state (like delay lines...) but keep the control parameter values */
        virtual void instanceClear() = 0;
 
        /**
         * Return a clone of the instance.
         *
         * @return a copy of the instance on success, otherwise a null pointer.
         */
        virtual dsp* clone() = 0;
    
        /**
         * Trigger the Meta* parameter with instance specific calls to 'declare' (key, value) metadata.
         *
         * @param m - the Meta* meta user
         */
        virtual void metadata(Meta* m) = 0;
    
        /**
         * DSP instance computation, to be called with successive in/out audio buffers.
         *
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
    
        /**
         * DSP instance computation: alternative method to be used by subclasses.
         *
         * @param date_usec - the timestamp in microsec given by audio driver.
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (either float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (either float, double or quad)
         *
         */
        virtual void compute(double /*date_usec*/, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
};

/**
 * Generic DSP decorator.
 */

class FAUST_API decorator_dsp : public dsp {

    protected:

        dsp* fDSP;

    public:

        decorator_dsp(dsp* dsp = nullptr):fDSP(dsp) {}
        virtual ~decorator_dsp() { delete fDSP; }

        virtual int getNumInputs() { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { fDSP->buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return fDSP->getSampleRate(); }
        virtual void init(int sample_rate) { fDSP->init(sample_rate); }
        virtual void instanceInit(int sample_rate) { fDSP->instanceInit(sample_rate); }
        virtual void instanceConstants(int sample_rate) { fDSP->instanceConstants(sample_rate); }
        virtual void instanceResetUserInterface() { fDSP->instanceResetUserInterface(); }
        virtual void instanceClear() { fDSP->instanceClear(); }
        virtual decorator_dsp* clone() { return new decorator_dsp(fDSP->clone()); }
        virtual void metadata(Meta* m) { fDSP->metadata(m); }
        // Beware: subclasses usually have to overload the two 'compute' methods
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(date_usec, count, inputs, outputs); }
    
};

/**
 * DSP factory class, used with LLVM and Interpreter backends
 * to create DSP instances from a compiled DSP program.
 */

class FAUST_API dsp_factory {
    
    protected:
    
        // So that to force sub-classes to use deleteDSPFactory(dsp_factory* factory);
        virtual ~dsp_factory() {}
    
    public:
    
        virtual std::string getName() = 0;
        virtual std::string getSHAKey() = 0;
        virtual std::string getDSPCode() = 0;
        virtual std::string getCompileOptions() = 0;
        virtual std::vector<std::string> getLibraryList() = 0;
        virtual std::vector<std::string> getIncludePathnames() = 0;
    
        virtual dsp* createDSPInstance() = 0;
    
        virtual void setMemoryManager(dsp_memory_manager* manager) = 0;
        virtual dsp_memory_manager* getMemoryManager() = 0;
    
};

// Denormal handling

#if defined (__SSE__)
#include <xmmintrin.h>
#endif

class FAUST_API ScopedNoDenormals {
    
    private:
    
        intptr_t fpsr = 0;
        
        void setFpStatusRegister(intptr_t fpsr_aux) noexcept
        {
        #if defined (__arm64__) || defined (__aarch64__)
            asm volatile("msr fpcr, %0" : : "ri" (fpsr_aux));
        #elif defined (__SSE__)
            // The volatile keyword here is needed to workaround a bug in AppleClang 13.0
            // which aggressively optimises away the variable otherwise
            volatile uint32_t fpsr_w = static_cast<uint32_t>(fpsr_aux);
            _mm_setcsr(fpsr_w);
        #endif
        }
        
        void getFpStatusRegister() noexcept
        {
        #if defined (__arm64__) || defined (__aarch64__)
            asm volatile("mrs %0, fpcr" : "=r" (fpsr));
        #elif defined (__SSE__)
            fpsr = static_cast<intptr_t>(_mm_getcsr());
        #endif
        }
    
    public:
    
        ScopedNoDenormals() noexcept
        {
        #if defined (__arm64__) || defined (__aarch64__)
            intptr_t mask = (1 << 24 /* FZ */);
        #elif defined (__SSE__)
        #if defined (__SSE2__)
            intptr_t mask = 0x8040;
        #else
            intptr_t mask = 0x8000;
        #endif
        #else
            intptr_t mask = 0x0000;
        #endif
            getFpStatusRegister();
            setFpStatusRegister(fpsr | mask);
        }
        
        ~ScopedNoDenormals() noexcept
        {
            setFpStatusRegister(fpsr);
        }

};

#define AVOIDDENORMALS ScopedNoDenormals ftz_scope;

#endif

/************************** END dsp.h **************************/
#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

class mydspSIG0 {
	
  private:
	
	int iVec2[2];
	int iRec17[2];
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
	}
	int getNumOutputsmydspSIG0() {
		return 1;
	}
	
	void instanceInitmydspSIG0(int sample_rate) {
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			iVec2[l4] = 0;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			iRec17[l5] = 0;
		}
	}
	
	void fillmydspSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			iVec2[0] = 1;
			iRec17[0] = (iVec2[1] + iRec17[1]) % 65536;
			table[i1] = std::sin(9.58738e-05f * float(iRec17[0]));
			iVec2[1] = iVec2[0];
			iRec17[1] = iRec17[0];
		}
	}

};

static mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
static void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

static float ftbl0mydspSIG0[65536];
static float mydsp_faustpower2_f(float value) {
	return value * value;
}

class mydsp : public dsp {
	
 private:
	
	int iVec0[2];
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fRec11[2];
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fButton0;
	float fVec1[2];
	int iRec14[2];
	float fConst2;
	float fConst3;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	float fRec18[2];
	FAUSTFLOAT fHslider4;
	float fRec15[2];
	float fConst6;
	float fConst8;
	float fConst9;
	float fConst10;
	float fRec21[2];
	float fRec20[3];
	float fConst12;
	float fConst13;
	float fVec3[2];
	float fConst14;
	float fConst15;
	float fRec19[2];
	float fConst16;
	float fRec13[2];
	float fRec12[2];
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT fButton1;
	float fVec4[2];
	int iRec23[2];
	float fConst18;
	float fConst19;
	FAUSTFLOAT fHslider6;
	float fConst23;
	float fConst25;
	float fConst26;
	float fConst27;
	float fConst34;
	float fConst35;
	float fConst37;
	float fConst38;
	FAUSTFLOAT fHslider7;
	float fConst39;
	float fRec30[2];
	FAUSTFLOAT fHslider8;
	float fRec29[2];
	float fRec28[2];
	float fRec27[2];
	float fRec33[2];
	float fRec32[2];
	float fRec31[2];
	float fRec36[2];
	float fRec35[2];
	float fRec34[2];
	float fRec39[2];
	float fRec38[2];
	float fRec37[2];
	float fRec42[2];
	float fRec41[2];
	float fRec40[2];
	FAUSTFLOAT fHslider9;
	float fConst40;
	int iRec43[2];
	float fRec26[3];
	float fConst41;
	float fConst42;
	float fRec25[3];
	float fConst44;
	float fConst45;
	float fVec5[2];
	float fConst46;
	float fConst47;
	float fRec24[2];
	FAUSTFLOAT fHslider10;
	FAUSTFLOAT fHslider11;
	FAUSTFLOAT fVslider1;
	float fConst51;
	float fConst53;
	float fConst54;
	float fConst55;
	float fConst56;
	float fConst57;
	float fConst58;
	float fConst59;
	float fConst60;
	FAUSTFLOAT fHslider12;
	float fRec47[4];
	FAUSTFLOAT fButton2;
	float fVec6[2];
	int iRec48[2];
	FAUSTFLOAT fHslider13;
	float fRec49[2];
	int iRec50[2];
	float fConst61;
	FAUSTFLOAT fHslider14;
	FAUSTFLOAT fHslider15;
	float fRec52[2];
	float fRec51[2];
	float fRec54[2];
	float fRec53[2];
	FAUSTFLOAT fHslider16;
	float fRec46[3];
	float fConst63;
	float fConst64;
	float fRec45[3];
	float fConst66;
	float fConst67;
	float fRec44[3];
	float fConst69;
	float fConst70;
	FAUSTFLOAT fHslider17;
	FAUSTFLOAT fVslider2;
	int IOTA0;
	float fVec7[8192];
	int iConst71;
	int iConst72;
	float fRec10[2];
	float fRec56[2];
	float fVec8[8192];
	int iConst73;
	int iConst74;
	float fRec55[2];
	float fRec58[2];
	float fVec9[8192];
	int iConst75;
	int iConst76;
	float fRec57[2];
	float fRec60[2];
	float fVec10[8192];
	int iConst77;
	int iConst78;
	float fRec59[2];
	float fRec62[2];
	float fVec11[8192];
	int iConst79;
	int iConst80;
	float fRec61[2];
	float fRec64[2];
	float fVec12[8192];
	int iConst81;
	int iConst82;
	float fRec63[2];
	float fRec66[2];
	float fVec13[8192];
	int iConst83;
	int iConst84;
	float fRec65[2];
	float fRec68[2];
	float fVec14[8192];
	int iConst85;
	int iConst86;
	float fRec67[2];
	float fVec15[2048];
	int iConst88;
	float fRec8[2];
	float fVec16[2048];
	int iConst90;
	float fRec6[2];
	float fVec17[2048];
	int iConst92;
	float fRec4[2];
	float fVec18[1024];
	int iConst94;
	float fRec2[2];
	float fRec78[2];
	float fVec19[8192];
	float fRec77[2];
	float fRec80[2];
	float fVec20[8192];
	float fRec79[2];
	float fRec82[2];
	float fVec21[8192];
	float fRec81[2];
	float fRec84[2];
	float fVec22[8192];
	float fRec83[2];
	float fRec86[2];
	float fVec23[8192];
	float fRec85[2];
	float fRec88[2];
	float fVec24[8192];
	float fRec87[2];
	float fRec90[2];
	float fVec25[8192];
	float fRec89[2];
	float fRec92[2];
	float fVec26[8192];
	float fRec91[2];
	float fVec27[2048];
	int iConst95;
	float fRec75[2];
	float fVec28[2048];
	int iConst96;
	float fRec73[2];
	float fVec29[2048];
	int iConst97;
	float fRec71[2];
	float fVec30[1024];
	int iConst98;
	float fRec69[2];
	FAUSTFLOAT fHslider18;
	FAUSTFLOAT fHslider19;
	FAUSTFLOAT fHslider20;
	FAUSTFLOAT fHslider21;
	float fVec31[262144];
	FAUSTFLOAT fHslider22;
	float fRec93[2];
	FAUSTFLOAT fButton3;
	float fVec32[2];
	int iRec95[2];
	FAUSTFLOAT fHslider23;
	float fConst99;
	FAUSTFLOAT fHslider24;
	FAUSTFLOAT fHslider25;
	FAUSTFLOAT fHslider26;
	float fRec98[2];
	float fVec33[2];
	float fVec34[4096];
	float fConst100;
	float fRec97[2];
	float fRec99[2];
	float fRec96[3];
	float fVec35[2];
	float fRec94[2];
	FAUSTFLOAT fHslider27;
	FAUSTFLOAT fVslider3;
	float fConst101;
	float fRec1[2];
	FAUSTFLOAT fHslider28;
	float fRec0[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/amp_follower_ar:author", "Jonatan Liljedahl, revised by Romain Michon");
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "0.2");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.8");
		m->declare("compile_options", "-a cApi.h -lang cpp -i -es 1 -mcd 16 -single -ftz 0");
		m->declare("compressors.lib/compression_gain_mono:author", "Julius O. Smith III");
		m->declare("compressors.lib/compression_gain_mono:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/compression_gain_mono:license", "MIT-style STK-4.3 license");
		m->declare("compressors.lib/compressor_lad_mono:author", "Julius O. Smith III");
		m->declare("compressors.lib/compressor_lad_mono:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/compressor_lad_mono:license", "MIT-style STK-4.3 license");
		m->declare("compressors.lib/compressor_mono:author", "Julius O. Smith III");
		m->declare("compressors.lib/compressor_mono:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/compressor_mono:license", "MIT-style STK-4.3 license");
		m->declare("compressors.lib/name", "Faust Compressor Effect Library");
		m->declare("compressors.lib/version", "0.4");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("envelopes.lib/adsr:author", "Yann Orlarey and Andrey Bundin");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.2");
		m->declare("filename", "main.dsp");
		m->declare("filters.lib/allpass_comb:author", "Julius O. Smith III");
		m->declare("filters.lib/allpass_comb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpass_comb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/bandpass0_bandstop1:author", "Julius O. Smith III");
		m->declare("filters.lib/bandpass0_bandstop1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/bandpass0_bandstop1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/bandpass:author", "Julius O. Smith III");
		m->declare("filters.lib/bandpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/bandpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpass3e:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass3e:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass3e:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpass6e:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass6e:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass6e:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass3e:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass3e:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass3e:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1sb:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1sb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1sb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.0");
		m->declare("name", "main");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.4");
		m->declare("oscillators.lib/lf_sawpos:author", "Bart Brouns, revised by Stéphane Letz");
		m->declare("oscillators.lib/lf_sawpos:licence", "STK-4.3");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.3");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
		m->declare("reverbs.lib/mono_freeverb:author", "Romain Michon");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/stereo_freeverb:author", "Romain Michon");
		m->declare("reverbs.lib/version", "0.2");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/onePoleSwitching:author", "Jonatan Liljedahl, revised by Dario Sanfilippo");
		m->declare("signals.lib/onePoleSwitching:licence", "STK-4.3");
		m->declare("signals.lib/version", "0.3");
	}

	virtual int getNumInputs() {
		return 0;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
		mydspSIG0* sig0 = newmydspSIG0();
		sig0->instanceInitmydspSIG0(sample_rate);
		sig0->fillmydspSIG0(65536, ftbl0mydspSIG0);
		deletemydspSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 1.0f / fConst0;
		fConst2 = std::max<float>(1.0f, 0.02f * fConst0);
		fConst3 = 1.0f / fConst2;
		float fConst4 = std::tan(31415.926f / fConst0);
		float fConst5 = mydsp_faustpower2_f(fConst4);
		fConst6 = 2.0f * (1.4122709f - 1.0f / fConst5);
		float fConst7 = 1.0f / fConst4;
		fConst8 = (fConst7 + -0.80263674f) / fConst4 + 1.4122709f;
		fConst9 = 1.0f / ((fConst7 + 0.80263674f) / fConst4 + 1.4122709f);
		fConst10 = 0.5f * fConst0;
		float fConst11 = 0.019809145f / fConst5;
		fConst12 = fConst11 + 1.1615164f;
		fConst13 = 2.0f * (1.1615164f - fConst11);
		fConst14 = 0.8224459f - fConst7;
		fConst15 = 1.0f / (fConst7 + 0.8224459f);
		fConst16 = std::exp(0.0f - 5.0f / fConst0);
		float fConst17 = 0.01f * fConst0;
		fConst18 = std::max<float>(1.0f, fConst17);
		fConst19 = 1.0f / fConst18;
		float fConst20 = std::tan(9424.778f / fConst0);
		float fConst21 = 1.0f / fConst20;
		float fConst22 = fConst21 + 1.2158854f;
		fConst23 = (1.2158854f - fConst21) / fConst22;
		float fConst24 = mydsp_faustpower2_f(fConst20);
		fConst25 = 2.0f * (0.70807946f - 1.0f / fConst24);
		fConst26 = (fConst21 + -0.5683306f) / fConst20 + 0.70807946f;
		fConst27 = 1.0f / ((fConst21 + 0.5683306f) / fConst20 + 0.70807946f);
		float fConst28 = std::tan(59690.26f / fConst0);
		float fConst29 = fConst0 * fConst28;
		float fConst30 = mydsp_faustpower2_f(std::sqrt(4.0f * mydsp_faustpower2_f(fConst0) * std::tan(15707.963f / fConst0) * fConst28));
		float fConst31 = 2.0f * fConst29 - 0.5f * (fConst30 / fConst29);
		float fConst32 = 2.0f * (fConst31 / fConst0);
		float fConst33 = mydsp_faustpower2_f(fConst1) * fConst30;
		fConst34 = fConst33 + (4.0f - fConst32);
		fConst35 = 2.0f * fConst33 + -8.0f;
		float fConst36 = fConst33 + fConst32 + 4.0f;
		fConst37 = 1.0f / fConst36;
		fConst38 = 0.2f * fConst0;
		fConst39 = 0.5f / fConst0;
		fConst40 = 1.2f * fConst0;
		fConst41 = 2.0f * (fConst31 / (fConst0 * fConst36));
		fConst42 = 0.0f - fConst41;
		float fConst43 = 0.8224459f / fConst24;
		fConst44 = fConst43 + 0.014026448f;
		fConst45 = 2.0f * (0.014026448f - fConst43);
		fConst46 = 1.2158854f / (fConst20 * fConst22);
		fConst47 = 0.0f - fConst46;
		float fConst48 = std::tan(753.98224f / fConst0);
		float fConst49 = mydsp_faustpower2_f(fConst48);
		float fConst50 = 1.0f / fConst49;
		fConst51 = 2.0f * (0.9351402f - fConst50);
		float fConst52 = 1.0f / fConst48;
		fConst53 = (fConst52 + -0.15748216f) / fConst48 + 0.9351402f;
		fConst54 = 1.0f / ((fConst52 + 0.15748216f) / fConst48 + 0.9351402f);
		fConst55 = 2.0f * (1.4500711f - fConst50);
		fConst56 = (fConst52 + -0.74313045f) / fConst48 + 1.4500711f;
		fConst57 = 1.0f / ((fConst52 + 0.74313045f) / fConst48 + 1.4500711f);
		fConst58 = 2.0f * (4.0767817f - fConst50);
		fConst59 = (fConst52 + -3.1897273f) / fConst48 + 4.0767817f;
		fConst60 = 1.0f / ((fConst52 + 3.1897273f) / fConst48 + 4.0767817f);
		fConst61 = 1.0f / std::max<float>(1.0f, 0.1f * fConst0);
		float fConst62 = 0.0017661728f / fConst49;
		fConst63 = fConst62 + 0.0004076782f;
		fConst64 = 2.0f * (0.0004076782f - fConst62);
		float fConst65 = 11.0520525f / fConst49;
		fConst66 = fConst65 + 1.4500711f;
		fConst67 = 2.0f * (1.4500711f - fConst65);
		float fConst68 = 50.06381f / fConst49;
		fConst69 = fConst68 + 0.9351402f;
		fConst70 = 2.0f * (0.9351402f - fConst68);
		iConst71 = int(0.036666665f * fConst0);
		iConst72 = iConst71 + 23;
		iConst73 = int(0.035306122f * fConst0);
		iConst74 = iConst73 + 23;
		iConst75 = int(0.033809524f * fConst0);
		iConst76 = iConst75 + 23;
		iConst77 = int(0.0322449f * fConst0);
		iConst78 = iConst77 + 23;
		iConst79 = int(0.030748298f * fConst0);
		iConst80 = iConst79 + 23;
		iConst81 = int(0.028956916f * fConst0);
		iConst82 = iConst81 + 23;
		iConst83 = int(0.026938776f * fConst0);
		iConst84 = iConst83 + 23;
		iConst85 = int(0.025306122f * fConst0);
		iConst86 = iConst85 + 23;
		int iConst87 = int(0.0126077095f * fConst0);
		iConst88 = std::min<int>(1024, std::max<int>(0, iConst87 + 22));
		int iConst89 = int(fConst17);
		iConst90 = std::min<int>(1024, std::max<int>(0, iConst89 + 22));
		int iConst91 = int(0.0077324263f * fConst0);
		iConst92 = std::min<int>(1024, std::max<int>(0, iConst91 + 22));
		int iConst93 = int(0.0051020407f * fConst0);
		iConst94 = std::min<int>(1024, std::max<int>(0, iConst93 + 22));
		iConst95 = std::min<int>(1024, std::max<int>(0, iConst87 + -1));
		iConst96 = std::min<int>(1024, std::max<int>(0, iConst89 + -1));
		iConst97 = std::min<int>(1024, std::max<int>(0, iConst91 + -1));
		iConst98 = std::min<int>(1024, std::max<int>(0, iConst93 + -1));
		fConst99 = 3.1415927f / fConst0;
		fConst100 = 25.0f * fConst0;
		fConst101 = std::exp(0.0f - 2.5f / fConst0);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.1f);
		fHslider1 = FAUSTFLOAT(0.15f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(0.07f);
		fHslider3 = FAUSTFLOAT(8e+02f);
		fHslider4 = FAUSTFLOAT(0.05f);
		fHslider5 = FAUSTFLOAT(0.05f);
		fVslider0 = FAUSTFLOAT(1.0f);
		fButton1 = FAUSTFLOAT(0.0f);
		fHslider6 = FAUSTFLOAT(0.038f);
		fHslider7 = FAUSTFLOAT(1.3e+03f);
		fHslider8 = FAUSTFLOAT(0.34f);
		fHslider9 = FAUSTFLOAT(0.5f);
		fHslider10 = FAUSTFLOAT(0.12f);
		fHslider11 = FAUSTFLOAT(0.05f);
		fVslider1 = FAUSTFLOAT(1.0f);
		fHslider12 = FAUSTFLOAT(0.26f);
		fButton2 = FAUSTFLOAT(0.0f);
		fHslider13 = FAUSTFLOAT(0.16f);
		fHslider14 = FAUSTFLOAT(0.1f);
		fHslider15 = FAUSTFLOAT(6e+01f);
		fHslider16 = FAUSTFLOAT(0.06f);
		fHslider17 = FAUSTFLOAT(0.1f);
		fVslider2 = FAUSTFLOAT(1.0f);
		fHslider18 = FAUSTFLOAT(0.1f);
		fHslider19 = FAUSTFLOAT(0.4f);
		fHslider20 = FAUSTFLOAT(0.05f);
		fHslider21 = FAUSTFLOAT(0.05f);
		fHslider22 = FAUSTFLOAT(0.23f);
		fButton3 = FAUSTFLOAT(0.0f);
		fHslider23 = FAUSTFLOAT(0.108f);
		fHslider24 = FAUSTFLOAT(0.56f);
		fHslider25 = FAUSTFLOAT(0.4f);
		fHslider26 = FAUSTFLOAT(6e+01f);
		fHslider27 = FAUSTFLOAT(0.12f);
		fVslider3 = FAUSTFLOAT(1.0f);
		fHslider28 = FAUSTFLOAT(0.4f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec11[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fVec1[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			iRec14[l3] = 0;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec18[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec15[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fRec21[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 3; l9 = l9 + 1) {
			fRec20[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fVec3[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fRec19[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec13[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = l13 + 1) {
			fRec12[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			fVec4[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			iRec23[l15] = 0;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			fRec30[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			fRec29[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			fRec28[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			fRec27[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			fRec33[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			fRec32[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
			fRec31[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = l23 + 1) {
			fRec36[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = l24 + 1) {
			fRec35[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = l25 + 1) {
			fRec34[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = l26 + 1) {
			fRec39[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = l27 + 1) {
			fRec38[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = l28 + 1) {
			fRec37[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2; l29 = l29 + 1) {
			fRec42[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = l30 + 1) {
			fRec41[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = l31 + 1) {
			fRec40[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = l32 + 1) {
			iRec43[l32] = 0;
		}
		for (int l33 = 0; l33 < 3; l33 = l33 + 1) {
			fRec26[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 3; l34 = l34 + 1) {
			fRec25[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 2; l35 = l35 + 1) {
			fVec5[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = l36 + 1) {
			fRec24[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 4; l37 = l37 + 1) {
			fRec47[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2; l38 = l38 + 1) {
			fVec6[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 2; l39 = l39 + 1) {
			iRec48[l39] = 0;
		}
		for (int l40 = 0; l40 < 2; l40 = l40 + 1) {
			fRec49[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2; l41 = l41 + 1) {
			iRec50[l41] = 0;
		}
		for (int l42 = 0; l42 < 2; l42 = l42 + 1) {
			fRec52[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 2; l43 = l43 + 1) {
			fRec51[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 2; l44 = l44 + 1) {
			fRec54[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 2; l45 = l45 + 1) {
			fRec53[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 3; l46 = l46 + 1) {
			fRec46[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 3; l47 = l47 + 1) {
			fRec45[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 3; l48 = l48 + 1) {
			fRec44[l48] = 0.0f;
		}
		IOTA0 = 0;
		for (int l49 = 0; l49 < 8192; l49 = l49 + 1) {
			fVec7[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 2; l50 = l50 + 1) {
			fRec10[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 2; l51 = l51 + 1) {
			fRec56[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 8192; l52 = l52 + 1) {
			fVec8[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 2; l53 = l53 + 1) {
			fRec55[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 2; l54 = l54 + 1) {
			fRec58[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 8192; l55 = l55 + 1) {
			fVec9[l55] = 0.0f;
		}
		for (int l56 = 0; l56 < 2; l56 = l56 + 1) {
			fRec57[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 2; l57 = l57 + 1) {
			fRec60[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 8192; l58 = l58 + 1) {
			fVec10[l58] = 0.0f;
		}
		for (int l59 = 0; l59 < 2; l59 = l59 + 1) {
			fRec59[l59] = 0.0f;
		}
		for (int l60 = 0; l60 < 2; l60 = l60 + 1) {
			fRec62[l60] = 0.0f;
		}
		for (int l61 = 0; l61 < 8192; l61 = l61 + 1) {
			fVec11[l61] = 0.0f;
		}
		for (int l62 = 0; l62 < 2; l62 = l62 + 1) {
			fRec61[l62] = 0.0f;
		}
		for (int l63 = 0; l63 < 2; l63 = l63 + 1) {
			fRec64[l63] = 0.0f;
		}
		for (int l64 = 0; l64 < 8192; l64 = l64 + 1) {
			fVec12[l64] = 0.0f;
		}
		for (int l65 = 0; l65 < 2; l65 = l65 + 1) {
			fRec63[l65] = 0.0f;
		}
		for (int l66 = 0; l66 < 2; l66 = l66 + 1) {
			fRec66[l66] = 0.0f;
		}
		for (int l67 = 0; l67 < 8192; l67 = l67 + 1) {
			fVec13[l67] = 0.0f;
		}
		for (int l68 = 0; l68 < 2; l68 = l68 + 1) {
			fRec65[l68] = 0.0f;
		}
		for (int l69 = 0; l69 < 2; l69 = l69 + 1) {
			fRec68[l69] = 0.0f;
		}
		for (int l70 = 0; l70 < 8192; l70 = l70 + 1) {
			fVec14[l70] = 0.0f;
		}
		for (int l71 = 0; l71 < 2; l71 = l71 + 1) {
			fRec67[l71] = 0.0f;
		}
		for (int l72 = 0; l72 < 2048; l72 = l72 + 1) {
			fVec15[l72] = 0.0f;
		}
		for (int l73 = 0; l73 < 2; l73 = l73 + 1) {
			fRec8[l73] = 0.0f;
		}
		for (int l74 = 0; l74 < 2048; l74 = l74 + 1) {
			fVec16[l74] = 0.0f;
		}
		for (int l75 = 0; l75 < 2; l75 = l75 + 1) {
			fRec6[l75] = 0.0f;
		}
		for (int l76 = 0; l76 < 2048; l76 = l76 + 1) {
			fVec17[l76] = 0.0f;
		}
		for (int l77 = 0; l77 < 2; l77 = l77 + 1) {
			fRec4[l77] = 0.0f;
		}
		for (int l78 = 0; l78 < 1024; l78 = l78 + 1) {
			fVec18[l78] = 0.0f;
		}
		for (int l79 = 0; l79 < 2; l79 = l79 + 1) {
			fRec2[l79] = 0.0f;
		}
		for (int l80 = 0; l80 < 2; l80 = l80 + 1) {
			fRec78[l80] = 0.0f;
		}
		for (int l81 = 0; l81 < 8192; l81 = l81 + 1) {
			fVec19[l81] = 0.0f;
		}
		for (int l82 = 0; l82 < 2; l82 = l82 + 1) {
			fRec77[l82] = 0.0f;
		}
		for (int l83 = 0; l83 < 2; l83 = l83 + 1) {
			fRec80[l83] = 0.0f;
		}
		for (int l84 = 0; l84 < 8192; l84 = l84 + 1) {
			fVec20[l84] = 0.0f;
		}
		for (int l85 = 0; l85 < 2; l85 = l85 + 1) {
			fRec79[l85] = 0.0f;
		}
		for (int l86 = 0; l86 < 2; l86 = l86 + 1) {
			fRec82[l86] = 0.0f;
		}
		for (int l87 = 0; l87 < 8192; l87 = l87 + 1) {
			fVec21[l87] = 0.0f;
		}
		for (int l88 = 0; l88 < 2; l88 = l88 + 1) {
			fRec81[l88] = 0.0f;
		}
		for (int l89 = 0; l89 < 2; l89 = l89 + 1) {
			fRec84[l89] = 0.0f;
		}
		for (int l90 = 0; l90 < 8192; l90 = l90 + 1) {
			fVec22[l90] = 0.0f;
		}
		for (int l91 = 0; l91 < 2; l91 = l91 + 1) {
			fRec83[l91] = 0.0f;
		}
		for (int l92 = 0; l92 < 2; l92 = l92 + 1) {
			fRec86[l92] = 0.0f;
		}
		for (int l93 = 0; l93 < 8192; l93 = l93 + 1) {
			fVec23[l93] = 0.0f;
		}
		for (int l94 = 0; l94 < 2; l94 = l94 + 1) {
			fRec85[l94] = 0.0f;
		}
		for (int l95 = 0; l95 < 2; l95 = l95 + 1) {
			fRec88[l95] = 0.0f;
		}
		for (int l96 = 0; l96 < 8192; l96 = l96 + 1) {
			fVec24[l96] = 0.0f;
		}
		for (int l97 = 0; l97 < 2; l97 = l97 + 1) {
			fRec87[l97] = 0.0f;
		}
		for (int l98 = 0; l98 < 2; l98 = l98 + 1) {
			fRec90[l98] = 0.0f;
		}
		for (int l99 = 0; l99 < 8192; l99 = l99 + 1) {
			fVec25[l99] = 0.0f;
		}
		for (int l100 = 0; l100 < 2; l100 = l100 + 1) {
			fRec89[l100] = 0.0f;
		}
		for (int l101 = 0; l101 < 2; l101 = l101 + 1) {
			fRec92[l101] = 0.0f;
		}
		for (int l102 = 0; l102 < 8192; l102 = l102 + 1) {
			fVec26[l102] = 0.0f;
		}
		for (int l103 = 0; l103 < 2; l103 = l103 + 1) {
			fRec91[l103] = 0.0f;
		}
		for (int l104 = 0; l104 < 2048; l104 = l104 + 1) {
			fVec27[l104] = 0.0f;
		}
		for (int l105 = 0; l105 < 2; l105 = l105 + 1) {
			fRec75[l105] = 0.0f;
		}
		for (int l106 = 0; l106 < 2048; l106 = l106 + 1) {
			fVec28[l106] = 0.0f;
		}
		for (int l107 = 0; l107 < 2; l107 = l107 + 1) {
			fRec73[l107] = 0.0f;
		}
		for (int l108 = 0; l108 < 2048; l108 = l108 + 1) {
			fVec29[l108] = 0.0f;
		}
		for (int l109 = 0; l109 < 2; l109 = l109 + 1) {
			fRec71[l109] = 0.0f;
		}
		for (int l110 = 0; l110 < 1024; l110 = l110 + 1) {
			fVec30[l110] = 0.0f;
		}
		for (int l111 = 0; l111 < 2; l111 = l111 + 1) {
			fRec69[l111] = 0.0f;
		}
		for (int l112 = 0; l112 < 262144; l112 = l112 + 1) {
			fVec31[l112] = 0.0f;
		}
		for (int l113 = 0; l113 < 2; l113 = l113 + 1) {
			fRec93[l113] = 0.0f;
		}
		for (int l114 = 0; l114 < 2; l114 = l114 + 1) {
			fVec32[l114] = 0.0f;
		}
		for (int l115 = 0; l115 < 2; l115 = l115 + 1) {
			iRec95[l115] = 0;
		}
		for (int l116 = 0; l116 < 2; l116 = l116 + 1) {
			fRec98[l116] = 0.0f;
		}
		for (int l117 = 0; l117 < 2; l117 = l117 + 1) {
			fVec33[l117] = 0.0f;
		}
		for (int l118 = 0; l118 < 4096; l118 = l118 + 1) {
			fVec34[l118] = 0.0f;
		}
		for (int l119 = 0; l119 < 2; l119 = l119 + 1) {
			fRec97[l119] = 0.0f;
		}
		for (int l120 = 0; l120 < 2; l120 = l120 + 1) {
			fRec99[l120] = 0.0f;
		}
		for (int l121 = 0; l121 < 3; l121 = l121 + 1) {
			fRec96[l121] = 0.0f;
		}
		for (int l122 = 0; l122 < 2; l122 = l122 + 1) {
			fVec35[l122] = 0.0f;
		}
		for (int l123 = 0; l123 < 2; l123 = l123 + 1) {
			fRec94[l123] = 0.0f;
		}
		for (int l124 = 0; l124 < 2; l124 = l124 + 1) {
			fRec1[l124] = 0.0f;
		}
		for (int l125 = 0; l125 < 2; l125 = l125 + 1) {
			fRec0[l125] = 0.0f;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("main");
		ui_interface->openHorizontalBox("audio");
		ui_interface->openHorizontalBox("fx");
		ui_interface->declare(0, "0", "");
		ui_interface->openHorizontalBox("sendfx");
		ui_interface->declare(0, "0", "");
		ui_interface->openHorizontalBox("rever sends");
		ui_interface->declare(&fHslider17, "0", "");
		ui_interface->declare(&fHslider17, "style", "knob");
		ui_interface->addHorizontalSlider("snr_rvb", &fHslider17, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider11, "1", "");
		ui_interface->declare(&fHslider11, "style", "knob");
		ui_interface->addHorizontalSlider("hh_rvb", &fHslider11, FAUSTFLOAT(0.05f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider5, "2", "");
		ui_interface->declare(&fHslider5, "style", "knob");
		ui_interface->addHorizontalSlider("cwbl_rvb", &fHslider5, FAUSTFLOAT(0.05f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("delay sends");
		ui_interface->declare(&fHslider18, "0", "");
		ui_interface->declare(&fHslider18, "style", "knob");
		ui_interface->addHorizontalSlider("snr_del", &fHslider18, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider20, "1", "");
		ui_interface->declare(&fHslider20, "style", "knob");
		ui_interface->addHorizontalSlider("hh_del", &fHslider20, FAUSTFLOAT(0.05f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider21, "2", "");
		ui_interface->declare(&fHslider21, "style", "knob");
		ui_interface->addHorizontalSlider("cwbl_del", &fHslider21, FAUSTFLOAT(0.05f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("delay");
		ui_interface->declare(&fHslider22, "0", "");
		ui_interface->declare(&fHslider22, "style", "knob");
		ui_interface->addHorizontalSlider("del_ratio", &fHslider22, FAUSTFLOAT(0.23f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider19, "1", "");
		ui_interface->declare(&fHslider19, "style", "knob");
		ui_interface->addHorizontalSlider("del_fb", &fHslider19, FAUSTFLOAT(0.4f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->declare(0, "1", "");
		ui_interface->openVerticalBox("cmp");
		ui_interface->addHorizontalSlider("cmp_att", &fHslider0, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("cmp_thrs", &fHslider28, FAUSTFLOAT(0.4f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("mix");
		ui_interface->declare(&fVslider3, "0", "");
		ui_interface->addVerticalSlider("kk_lvl", &fVslider3, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider2, "1", "");
		ui_interface->addVerticalSlider("snr_lvl", &fVslider2, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider1, "2", "");
		ui_interface->addVerticalSlider("hh_lvl", &fVslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fVslider0, "3", "");
		ui_interface->addVerticalSlider("cwbl_lvl", &fVslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("drums");
		ui_interface->declare(0, "0", "");
		ui_interface->openVerticalBox("kick");
		ui_interface->declare(0, "0", "");
		ui_interface->openHorizontalBox("kk_macros");
		ui_interface->declare(&fHslider25, "0", "");
		ui_interface->declare(&fHslider25, "style", "knob");
		ui_interface->addHorizontalSlider("kk_color", &fHslider25, FAUSTFLOAT(0.4f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider23, "1", "");
		ui_interface->declare(&fHslider23, "style", "knob");
		ui_interface->addHorizontalSlider("kk_decay", &fHslider23, FAUSTFLOAT(0.108f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider24, "2", "");
		ui_interface->declare(&fHslider24, "style", "knob");
		ui_interface->addHorizontalSlider("kk_noise", &fHslider24, FAUSTFLOAT(0.56f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider27, "3", "");
		ui_interface->declare(&fHslider27, "style", "knob");
		ui_interface->addHorizontalSlider("kk_drive", &fHslider27, FAUSTFLOAT(0.12f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->declare(&fButton3, "1", "");
		ui_interface->addButton("kk_gate", &fButton3);
		ui_interface->declare(&fHslider26, "style", "knob");
		ui_interface->addHorizontalSlider("kk_freq", &fHslider26, FAUSTFLOAT(6e+01f), FAUSTFLOAT(4e+01f), FAUSTFLOAT(1e+04f), FAUSTFLOAT(0.001f));
		ui_interface->closeBox();
		ui_interface->declare(0, "1", "");
		ui_interface->openVerticalBox("snare");
		ui_interface->declare(0, "0", "");
		ui_interface->openHorizontalBox("snr_macros");
		ui_interface->declare(&fHslider14, "0", "");
		ui_interface->declare(&fHslider14, "style", "knob");
		ui_interface->addHorizontalSlider("snr_color", &fHslider14, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider13, "1", "");
		ui_interface->declare(&fHslider13, "style", "knob");
		ui_interface->addHorizontalSlider("snr_decay", &fHslider13, FAUSTFLOAT(0.16f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider12, "2", "");
		ui_interface->declare(&fHslider12, "style", "knob");
		ui_interface->addHorizontalSlider("snr_noise", &fHslider12, FAUSTFLOAT(0.26f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider16, "3", "");
		ui_interface->declare(&fHslider16, "style", "knob");
		ui_interface->addHorizontalSlider("snr_drive", &fHslider16, FAUSTFLOAT(0.06f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->declare(&fButton2, "1", "");
		ui_interface->addButton("snr_gate", &fButton2);
		ui_interface->declare(&fHslider15, "style", "knob");
		ui_interface->addHorizontalSlider("snr_freq", &fHslider15, FAUSTFLOAT(6e+01f), FAUSTFLOAT(4e+01f), FAUSTFLOAT(1e+04f), FAUSTFLOAT(0.001f));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openVerticalBox("hh");
		ui_interface->declare(0, "0", "");
		ui_interface->openHorizontalBox("hh_macros");
		ui_interface->declare(&fHslider8, "0", "");
		ui_interface->declare(&fHslider8, "style", "knob");
		ui_interface->addHorizontalSlider("hh_color", &fHslider8, FAUSTFLOAT(0.34f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider6, "1", "");
		ui_interface->declare(&fHslider6, "style", "knob");
		ui_interface->addHorizontalSlider("hh_decay", &fHslider6, FAUSTFLOAT(0.038f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider9, "2", "");
		ui_interface->declare(&fHslider9, "style", "knob");
		ui_interface->addHorizontalSlider("hh_noise", &fHslider9, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider10, "3", "");
		ui_interface->declare(&fHslider10, "style", "knob");
		ui_interface->addHorizontalSlider("hh_drive", &fHslider10, FAUSTFLOAT(0.12f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->declare(&fButton1, "1", "");
		ui_interface->addButton("hh_gate", &fButton1);
		ui_interface->declare(&fHslider7, "style", "knob");
		ui_interface->addHorizontalSlider("hh_freq", &fHslider7, FAUSTFLOAT(1.3e+03f), FAUSTFLOAT(4e+01f), FAUSTFLOAT(1e+04f), FAUSTFLOAT(0.001f));
		ui_interface->closeBox();
		ui_interface->declare(0, "3", "");
		ui_interface->openVerticalBox("cwbl");
		ui_interface->declare(0, "0", "");
		ui_interface->openHorizontalBox("cwbl_macros");
		ui_interface->declare(&fHslider4, "0", "");
		ui_interface->declare(&fHslider4, "style", "knob");
		ui_interface->addHorizontalSlider("cwbl_color", &fHslider4, FAUSTFLOAT(0.05f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->declare(&fHslider1, "style", "knob");
		ui_interface->addHorizontalSlider("cwbl_decay", &fHslider1, FAUSTFLOAT(0.15f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider2, "2", "");
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->addHorizontalSlider("cwbl_detune", &fHslider2, FAUSTFLOAT(0.07f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->declare(&fButton0, "1", "");
		ui_interface->addButton("cwbl_gate", &fButton0);
		ui_interface->declare(&fHslider3, "style", "knob");
		ui_interface->addHorizontalSlider("cwbl_freq", &fHslider3, FAUSTFLOAT(8e+02f), FAUSTFLOAT(4e+01f), FAUSTFLOAT(1e+04f), FAUSTFLOAT(0.001f));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = float(fHslider0);
		float fSlow1 = 0.5f * fSlow0;
		int iSlow2 = std::fabs(fSlow1) < 1.1920929e-07f;
		float fThen1 = std::exp(0.0f - fConst1 / ((iSlow2) ? 1.0f : fSlow1));
		float fSlow3 = ((iSlow2) ? 0.0f : fThen1);
		float fSlow4 = 0.77f * float(fHslider1);
		float fSlow5 = std::max<float>(fSlow4 + -0.07f, 0.05f);
		float fSlow6 = 0.5f * fSlow5;
		int iSlow7 = std::fabs(fSlow6) < 1.1920929e-07f;
		float fThen3 = std::exp(0.0f - fConst1 / ((iSlow7) ? 1.0f : fSlow6));
		float fSlow8 = ((iSlow7) ? 0.0f : fThen3);
		float fSlow9 = float(fButton0);
		float fSlow10 = fSlow4 + 0.03f;
		float fSlow11 = 1.0f / std::max<float>(1.0f, fConst0 * fSlow10);
		float fSlow12 = 1e+02f * float(fHslider2);
		float fSlow13 = std::max<float>(float(fHslider3) + -2.2e+02f, 4e+01f);
		float fSlow14 = fConst1 * (0.5f * fSlow13 + 4.4e+02f);
		float fSlow15 = float(fHslider4);
		float fSlow16 = 5e+03f * fSlow15;
		float fSlow17 = 1.5f * fSlow13;
		float fSlow18 = 1.0f / std::max<float>(1.0f, fConst10 * fSlow10);
		float fSlow19 = fSlow13 + fSlow12;
		int iSlow20 = std::fabs(fSlow5) < 1.1920929e-07f;
		float fThen9 = std::exp(0.0f - fConst1 / ((iSlow20) ? 1.0f : fSlow5));
		float fSlow21 = ((iSlow20) ? 0.0f : fThen9);
		float fSlow22 = 1.0f - fSlow8;
		float fSlow23 = float(fVslider0);
		float fSlow24 = fSlow23 * float(fHslider5);
		float fSlow25 = float(fButton1);
		float fSlow26 = 0.77f * float(fHslider6) + 0.03f;
		float fSlow27 = 1.0f / std::max<float>(1.0f, fConst0 * fSlow26);
		float fSlow28 = 1.0f / std::max<float>(1.0f, fConst38 * fSlow26);
		float fSlow29 = std::max<float>(float(fHslider7) + -2.2e+02f, 4e+01f);
		float fSlow30 = fConst39 * fSlow29;
		float fSlow31 = 3.6e+03f * float(fHslider8) + 4e+02f;
		float fSlow32 = 3.0f * fSlow29;
		float fSlow33 = 0.63f * fSlow29;
		float fSlow34 = 4.16f * fSlow29;
		float fSlow35 = 5.43f * fSlow29;
		float fSlow36 = 6.78f * fSlow29;
		float fSlow37 = 0.3f * float(fHslider9);
		float fSlow38 = 0.22222222f * (0.8f - fSlow37);
		float fSlow39 = 1.0f / std::max<float>(1.0f, fConst40 * fSlow26);
		float fSlow40 = 4.656613e-10f * (fSlow37 + 0.2f);
		float fSlow41 = float(fHslider10);
		float fSlow42 = std::pow(1e+01f, 0.8f * fSlow41);
		float fSlow43 = 1.0f - 0.4f * fSlow41;
		float fSlow44 = float(fVslider1);
		float fSlow45 = fSlow44 * float(fHslider11);
		float fSlow46 = float(fHslider12);
		float fSlow47 = 4.656613e-10f * fSlow46;
		float fSlow48 = 1.0f - fSlow46;
		float fSlow49 = float(fButton2);
		int iSlow50 = fSlow49 == 0.0f;
		float fSlow51 = 0.59f * float(fHslider13);
		float fSlow52 = fSlow51 + 0.01f;
		float fSlow53 = 1.0f / std::max<float>(1.0f, fConst0 * fSlow52);
		float fSlow54 = 1.0f / std::max<float>(1.0f, fConst0 * (fSlow51 + 0.11f));
		float fSlow55 = 1.0f / std::max<float>(1.0f, fConst10 * fSlow52);
		float fSlow56 = 2.5f * float(fHslider14) + 1.5f;
		float fSlow57 = std::max<float>(float(fHslider15) + -2.2e+02f, 4e+01f);
		float fSlow58 = fSlow57 * fSlow56;
		float fSlow59 = 1.5f * fSlow58;
		float fSlow60 = 1.5f * fSlow57;
		float fSlow61 = float(fHslider16);
		float fSlow62 = std::pow(1e+01f, 0.8f * fSlow61);
		float fSlow63 = 1.0f - 0.4f * fSlow61;
		float fSlow64 = float(fVslider2);
		float fSlow65 = fConst54 * fSlow64 * float(fHslider17);
		float fSlow66 = fConst54 * fSlow64 * float(fHslider18);
		float fSlow67 = 0.85f * float(fHslider19);
		float fSlow68 = fSlow44 * float(fHslider20);
		float fSlow69 = fSlow23 * float(fHslider21);
		float fSlow70 = 4.0f * float(fHslider22) + 1.0f;
		int iSlow71 = int(std::min<float>(fConst0 / fSlow70, std::max<float>(0.0f, fConst0 * fSlow70)));
		float fSlow72 = fConst54 * fSlow64;
		float fSlow73 = float(fButton3);
		float fSlow74 = 0.77f * float(fHslider23);
		float fSlow75 = 1.0f / std::max<float>(1.0f, fConst0 * (fSlow74 + 0.03f));
		float fSlow76 = 1.0f / std::max<float>(1.0f, fConst0 * std::log10(std::exp(fSlow74 + -0.17f)));
		float fSlow77 = float(fHslider24);
		float fSlow78 = 0.00016666666f * (0.0f - 3e+03f * fSlow77);
		float fSlow79 = 0.0f - fSlow78;
		float fSlow80 = 6e+03f * fSlow77;
		float fSlow81 = std::max<float>(float(fHslider26) + -2.2e+02f, 4e+01f);
		float fSlow82 = fSlow81 * (9.02f * float(fHslider25) + 0.98f);
		float fSlow83 = 0.5f * fSlow81;
		float fSlow84 = fSlow78 + 1.0f;
		float fSlow85 = float(fHslider27);
		float fSlow86 = std::pow(1e+01f, 0.8f * fSlow85);
		float fSlow87 = float(fVslider3) * (1.0f - 0.4f * fSlow85);
		int iSlow88 = std::fabs(fSlow0) < 1.1920929e-07f;
		float fThen12 = std::exp(0.0f - fConst1 / ((iSlow88) ? 1.0f : fSlow0));
		float fSlow89 = ((iSlow88) ? 0.0f : fThen12);
		float fSlow90 = 3e+01f * float(fHslider28);
		float fSlow91 = 1.0f - fSlow3;
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 1;
			fRec11[0] = 0.2f * fRec11[1] + 0.8f * fRec10[1];
			fVec1[0] = fSlow9;
			iRec14[0] = (iRec14[1] + (iRec14[1] > 0)) * (fSlow9 <= fVec1[1]) + (fSlow9 > fVec1[1]);
			float fTemp0 = float(iRec14[0]);
			float fTemp1 = fConst3 * fTemp0;
			float fTemp2 = fConst2 - fTemp0;
			fRec18[0] = fSlow14 + (fRec18[1] - std::floor(fSlow14 + fRec18[1]));
			float fTemp3 = ftbl0mydspSIG0[int(65536.0f * fRec18[0])];
			float fTemp4 = std::max<float>(1.1920929e-07f, std::fabs(fSlow17 + (fSlow16 * fTemp3 - fSlow12)));
			float fTemp5 = fRec15[1] + fConst1 * fTemp4;
			float fTemp6 = fTemp5 + -1.0f;
			int iTemp7 = fTemp6 < 0.0f;
			fRec15[0] = ((iTemp7) ? fTemp5 : fTemp6);
			float fThen5 = fTemp5 + fTemp6 * (1.0f - fConst0 / fTemp4);
			float fRec16 = ((iTemp7) ? fTemp5 : fThen5);
			float fTemp8 = std::max<float>(1.1920929e-07f, std::fabs(fSlow19 + fSlow15 * (5e+03f * fTemp3 + 5e+01f * std::max<float>(0.0f, std::min<float>(fTemp1, fSlow18 * fTemp2 + 1.0f)))));
			float fTemp9 = fRec21[1] + fConst1 * fTemp8;
			float fTemp10 = fTemp9 + -1.0f;
			int iTemp11 = fTemp10 < 0.0f;
			fRec21[0] = ((iTemp11) ? fTemp9 : fTemp10);
			float fThen7 = fTemp9 + fTemp10 * (1.0f - fConst0 / fTemp8);
			float fRec22 = ((iTemp11) ? fTemp9 : fThen7);
			fRec20[0] = 2.0f * fRec22 + (-1.0f - fConst9 * (fConst8 * fRec20[2] + fConst6 * fRec20[1]));
			float fTemp12 = fConst12 * fRec20[0] + fConst13 * fRec20[1] + fConst12 * fRec20[2];
			fVec3[0] = fTemp12;
			fRec19[0] = 0.0f - fConst15 * (fConst14 * fRec19[1] - fConst9 * (fTemp12 + fVec3[1]));
			float fTemp13 = (fRec19[0] + 2.0f * fRec16 + -1.0f) * std::max<float>(0.0f, std::min<float>(fTemp1, fSlow11 * fTemp2 + 1.0f));
			float fTemp14 = std::fabs(fTemp13);
			float fTemp15 = ((fTemp14 > fRec13[1]) ? fSlow21 : fConst16);
			fRec13[0] = fTemp14 * (1.0f - fTemp15) + fRec13[1] * fTemp15;
			fRec12[0] = fSlow22 * (0.0f - 0.875f * std::max<float>(2e+01f * std::log10(std::max<float>(1.1754944e-38f, fRec13[0])) + 25.0f, 0.0f)) + fSlow8 * fRec12[1];
			float fTemp16 = fTemp13 * std::pow(1e+01f, 0.05f * fRec12[0]);
			fVec4[0] = fSlow25;
			iRec23[0] = (iRec23[1] + (iRec23[1] > 0)) * (fSlow25 <= fVec4[1]) + (fSlow25 > fVec4[1]);
			float fTemp17 = float(iRec23[0]);
			float fTemp18 = fConst19 * fTemp17;
			float fTemp19 = fConst18 - fTemp17;
			float fTemp20 = 1e+02f * std::max<float>(0.0f, std::min<float>(fTemp18, fSlow28 * fTemp19 + 1.0f));
			fRec30[0] = fSlow30 + (fRec30[1] - std::floor(fSlow30 + fRec30[1]));
			float fTemp21 = fSlow31 * ftbl0mydspSIG0[int(65536.0f * fRec30[0])];
			float fTemp22 = fTemp21 + fTemp20;
			float fTemp23 = fRec29[1] + fConst1 * (fSlow32 + fTemp22 + fRec28[1]);
			fRec29[0] = fTemp23 - std::floor(fTemp23);
			fRec28[0] = ftbl0mydspSIG0[int(65536.0f * fRec29[0])] + 0.63f * fRec27[1];
			fRec27[0] = fRec28[0];
			float fTemp24 = fRec33[1] + fConst1 * (fSlow33 + fTemp20 + fRec32[1] + fTemp21);
			fRec33[0] = fTemp24 - std::floor(fTemp24);
			fRec32[0] = ftbl0mydspSIG0[int(65536.0f * fRec33[0])] + 0.63f * fRec31[1];
			fRec31[0] = fRec32[0];
			float fTemp25 = fRec36[1] + fConst1 * (fSlow34 + fTemp22 + fRec35[1]);
			fRec36[0] = fTemp25 - std::floor(fTemp25);
			fRec35[0] = ftbl0mydspSIG0[int(65536.0f * fRec36[0])] + 0.63f * fRec34[1];
			fRec34[0] = fRec35[0];
			float fTemp26 = fRec39[1] + fConst1 * (fSlow35 + fTemp22 + fRec38[1]);
			fRec39[0] = fTemp26 - std::floor(fTemp26);
			fRec38[0] = ftbl0mydspSIG0[int(65536.0f * fRec39[0])] + 0.63f * fRec37[1];
			fRec37[0] = fRec38[0];
			float fTemp27 = fRec42[1] + fConst1 * (fSlow36 + fTemp22 + fRec41[1]);
			fRec42[0] = fTemp27 - std::floor(fTemp27);
			fRec41[0] = ftbl0mydspSIG0[int(65536.0f * fRec42[0])] + 0.63f * fRec40[1];
			fRec40[0] = fRec41[0];
			iRec43[0] = 1103515245 * iRec43[1] + 12345;
			float fTemp28 = float(iRec43[0]);
			fRec26[0] = fSlow40 * fTemp28 * std::max<float>(0.0f, std::min<float>(fTemp18, fSlow39 * fTemp19 + 1.0f)) + fSlow38 * (fRec40[0] + fRec37[0] + fRec34[0] + 0.25f * fRec31[0] + 0.5f * fRec27[0]) - fConst37 * (fConst35 * fRec26[1] + fConst34 * fRec26[2]);
			fRec25[0] = fConst41 * fRec26[0] + fConst42 * fRec26[2] - fConst27 * (fConst26 * fRec25[2] + fConst25 * fRec25[1]);
			float fTemp29 = fConst44 * fRec25[0] + fConst45 * fRec25[1] + fConst44 * fRec25[2];
			fVec5[0] = fTemp29;
			fRec24[0] = fConst27 * (fConst47 * fVec5[1] + fConst46 * fTemp29) - fConst23 * fRec24[1];
			float fTemp30 = std::max<float>(-1.0f, std::min<float>(1.0f, fSlow42 * fRec24[0] * std::max<float>(0.0f, std::min<float>(fTemp18, fSlow27 * fTemp19 + 1.0f))));
			float fTemp31 = std::min<float>(1.0f, std::max<float>(-1.0f, fSlow43 * fTemp30 * (1.0f - 0.33333334f * mydsp_faustpower2_f(fTemp30))));
			fRec47[0] = 0.5221894f * fRec47[3] + 4.656613e-10f * fTemp28 + 2.494956f * fRec47[1] - 2.0172658f * fRec47[2];
			float fTemp32 = 0.049922034f * fRec47[0] + 0.0506127f * fRec47[2] - (0.095993534f * fRec47[1] + 0.004408786f * fRec47[3]);
			fVec6[0] = fSlow49;
			iRec48[0] = iSlow50 * (iRec48[1] + 1);
			fRec49[0] = fSlow49 + fRec49[1] * float(fVec6[1] >= fSlow49);
			iRec50[0] = (iRec50[1] + (iRec50[1] > 0)) * (fSlow49 <= fVec6[1]) + (fSlow49 > fVec6[1]);
			float fTemp33 = float(iRec50[0]);
			float fTemp34 = fConst19 * fTemp33;
			float fTemp35 = fConst18 - fTemp33;
			float fTemp36 = std::max<float>(0.0f, std::min<float>(fTemp34, fConst61 * fTemp35 + 1.0f)) * (1.6e+03f * fTemp32 + 1.8e+02f);
			float fTemp37 = fRec52[1] + fConst1 * (fSlow59 + fTemp36);
			fRec52[0] = fTemp37 - std::floor(fTemp37);
			float fTemp38 = fSlow56 * fTemp36;
			float fTemp39 = fRec51[1] + fConst1 * (fTemp38 + fSlow60 * ftbl0mydspSIG0[int(65536.0f * fRec52[0])]);
			fRec51[0] = fTemp39 - std::floor(fTemp39);
			float fTemp40 = fRec54[1] + fConst1 * (fSlow58 + fTemp36);
			fRec54[0] = fTemp40 - std::floor(fTemp40);
			float fTemp41 = fRec53[1] + fConst1 * (fSlow57 * ftbl0mydspSIG0[int(65536.0f * fRec54[0])] + fTemp38);
			fRec53[0] = fTemp41 - std::floor(fTemp41);
			float fTemp42 = std::max<float>(-1.0f, std::min<float>(1.0f, fSlow62 * (fSlow48 * (ftbl0mydspSIG0[int(65536.0f * fRec53[0])] + ftbl0mydspSIG0[int(65536.0f * fRec51[0])]) * std::max<float>(0.0f, std::min<float>(fTemp34, fSlow55 * fTemp35 + 1.0f)) + fSlow46 * mydsp_faustpower2_f(std::max<float>(0.0f, std::min<float>(fConst19 * fRec49[0], std::max<float>(fSlow54 * (fConst18 - fRec49[0]) + 1.0f, 0.0f)) * (1.0f - fSlow53 * float(iRec48[0])))) * (fSlow48 * fTemp32 + fSlow47 * fTemp28))));
			fRec46[0] = fSlow63 * fTemp42 * (1.0f - 0.33333334f * mydsp_faustpower2_f(fTemp42)) - fConst60 * (fConst59 * fRec46[2] + fConst58 * fRec46[1]);
			fRec45[0] = fConst60 * (fConst63 * fRec46[0] + fConst64 * fRec46[1] + fConst63 * fRec46[2]) - fConst57 * (fConst56 * fRec45[2] + fConst55 * fRec45[1]);
			fRec44[0] = fConst57 * (fConst66 * fRec45[0] + fConst67 * fRec45[1] + fConst66 * fRec45[2]) - fConst54 * (fConst53 * fRec44[2] + fConst51 * fRec44[1]);
			float fTemp43 = fConst69 * fRec44[0] + fConst70 * fRec44[1] + fConst69 * fRec44[2];
			float fTemp44 = 0.2f * (fSlow65 * fTemp43 + fSlow45 * fTemp31 + fSlow24 * fTemp16);
			fVec7[IOTA0 & 8191] = fTemp44 + 0.95f * fRec11[0];
			fRec10[0] = fVec7[(IOTA0 - iConst72) & 8191];
			fRec56[0] = 0.2f * fRec56[1] + 0.8f * fRec55[1];
			fVec8[IOTA0 & 8191] = fTemp44 + 0.95f * fRec56[0];
			fRec55[0] = fVec8[(IOTA0 - iConst74) & 8191];
			fRec58[0] = 0.2f * fRec58[1] + 0.8f * fRec57[1];
			fVec9[IOTA0 & 8191] = fTemp44 + 0.95f * fRec58[0];
			fRec57[0] = fVec9[(IOTA0 - iConst76) & 8191];
			fRec60[0] = 0.2f * fRec60[1] + 0.8f * fRec59[1];
			fVec10[IOTA0 & 8191] = fTemp44 + 0.95f * fRec60[0];
			fRec59[0] = fVec10[(IOTA0 - iConst78) & 8191];
			fRec62[0] = 0.2f * fRec62[1] + 0.8f * fRec61[1];
			fVec11[IOTA0 & 8191] = fTemp44 + 0.95f * fRec62[0];
			fRec61[0] = fVec11[(IOTA0 - iConst80) & 8191];
			fRec64[0] = 0.2f * fRec64[1] + 0.8f * fRec63[1];
			fVec12[IOTA0 & 8191] = fTemp44 + 0.95f * fRec64[0];
			fRec63[0] = fVec12[(IOTA0 - iConst82) & 8191];
			fRec66[0] = 0.2f * fRec66[1] + 0.8f * fRec65[1];
			fVec13[IOTA0 & 8191] = fTemp44 + 0.95f * fRec66[0];
			fRec65[0] = fVec13[(IOTA0 - iConst84) & 8191];
			fRec68[0] = 0.2f * fRec68[1] + 0.8f * fRec67[1];
			fVec14[IOTA0 & 8191] = fTemp44 + 0.95f * fRec68[0];
			fRec67[0] = fVec14[(IOTA0 - iConst86) & 8191];
			float fTemp45 = fRec67[0] + fRec65[0] + fRec63[0] + fRec61[0] + fRec59[0] + fRec57[0] + fRec55[0] + fRec10[0] + 0.5f * fRec8[1];
			fVec15[IOTA0 & 2047] = fTemp45;
			fRec8[0] = fVec15[(IOTA0 - iConst88) & 2047];
			float fRec9 = 0.0f - 0.5f * fTemp45;
			float fTemp46 = fRec8[1] + fRec9 + 0.5f * fRec6[1];
			fVec16[IOTA0 & 2047] = fTemp46;
			fRec6[0] = fVec16[(IOTA0 - iConst90) & 2047];
			float fRec7 = 0.0f - 0.5f * fTemp46;
			float fTemp47 = fRec6[1] + fRec7 + 0.5f * fRec4[1];
			fVec17[IOTA0 & 2047] = fTemp47;
			fRec4[0] = fVec17[(IOTA0 - iConst92) & 2047];
			float fRec5 = 0.0f - 0.5f * fTemp47;
			float fTemp48 = fRec4[1] + fRec5 + 0.5f * fRec2[1];
			fVec18[IOTA0 & 1023] = fTemp48;
			fRec2[0] = fVec18[(IOTA0 - iConst94) & 1023];
			float fRec3 = 0.0f - 0.5f * fTemp48;
			fRec78[0] = 0.2f * fRec78[1] + 0.8f * fRec77[1];
			fVec19[IOTA0 & 8191] = fTemp44 + 0.95f * fRec78[0];
			fRec77[0] = fVec19[(IOTA0 - iConst71) & 8191];
			fRec80[0] = 0.2f * fRec80[1] + 0.8f * fRec79[1];
			fVec20[IOTA0 & 8191] = fTemp44 + 0.95f * fRec80[0];
			fRec79[0] = fVec20[(IOTA0 - iConst73) & 8191];
			fRec82[0] = 0.2f * fRec82[1] + 0.8f * fRec81[1];
			fVec21[IOTA0 & 8191] = fTemp44 + 0.95f * fRec82[0];
			fRec81[0] = fVec21[(IOTA0 - iConst75) & 8191];
			fRec84[0] = 0.2f * fRec84[1] + 0.8f * fRec83[1];
			fVec22[IOTA0 & 8191] = fTemp44 + 0.95f * fRec84[0];
			fRec83[0] = fVec22[(IOTA0 - iConst77) & 8191];
			fRec86[0] = 0.2f * fRec86[1] + 0.8f * fRec85[1];
			fVec23[IOTA0 & 8191] = fTemp44 + 0.95f * fRec86[0];
			fRec85[0] = fVec23[(IOTA0 - iConst79) & 8191];
			fRec88[0] = 0.2f * fRec88[1] + 0.8f * fRec87[1];
			fVec24[IOTA0 & 8191] = fTemp44 + 0.95f * fRec88[0];
			fRec87[0] = fVec24[(IOTA0 - iConst81) & 8191];
			fRec90[0] = 0.2f * fRec90[1] + 0.8f * fRec89[1];
			fVec25[IOTA0 & 8191] = fTemp44 + 0.95f * fRec90[0];
			fRec89[0] = fVec25[(IOTA0 - iConst83) & 8191];
			fRec92[0] = 0.2f * fRec92[1] + 0.8f * fRec91[1];
			fVec26[IOTA0 & 8191] = 0.95f * fRec92[0] + fTemp44;
			fRec91[0] = fVec26[(IOTA0 - iConst85) & 8191];
			float fTemp49 = fRec91[0] + fRec89[0] + fRec87[0] + fRec85[0] + fRec83[0] + fRec81[0] + fRec79[0] + fRec77[0] + 0.5f * fRec75[1];
			fVec27[IOTA0 & 2047] = fTemp49;
			fRec75[0] = fVec27[(IOTA0 - iConst95) & 2047];
			float fRec76 = 0.0f - 0.5f * fTemp49;
			float fTemp50 = fRec75[1] + fRec76 + 0.5f * fRec73[1];
			fVec28[IOTA0 & 2047] = fTemp50;
			fRec73[0] = fVec28[(IOTA0 - iConst96) & 2047];
			float fRec74 = 0.0f - 0.5f * fTemp50;
			float fTemp51 = fRec73[1] + fRec74 + 0.5f * fRec71[1];
			fVec29[IOTA0 & 2047] = fTemp51;
			fRec71[0] = fVec29[(IOTA0 - iConst97) & 2047];
			float fRec72 = 0.0f - 0.5f * fTemp51;
			float fTemp52 = fRec71[1] + fRec72 + 0.5f * fRec69[1];
			fVec30[IOTA0 & 1023] = fTemp52;
			fRec69[0] = fVec30[(IOTA0 - iConst98) & 1023];
			float fRec70 = 0.0f - 0.5f * fTemp52;
			fVec31[IOTA0 & 262143] = fSlow69 * fTemp16 + fSlow68 * fTemp31 + fSlow67 * fRec93[1] + fSlow66 * fTemp43;
			fRec93[0] = fVec31[(IOTA0 - iSlow71) & 262143];
			fVec32[0] = fSlow73;
			iRec95[0] = (iRec95[1] + (iRec95[1] > 0)) * (fSlow73 <= fVec32[1]) + (fSlow73 > fVec32[1]);
			float fTemp53 = float(iRec95[0]);
			float fTemp54 = fConst19 * fTemp53;
			float fTemp55 = fConst18 - fTemp53;
			float fTemp56 = std::max<float>(0.0f, std::min<float>(fTemp54, fSlow75 * fTemp55 + 1.0f));
			float fTemp57 = std::tan(fConst99 * (6e+01f - 4e+01f * fTemp56));
			float fTemp58 = 1.0f / fTemp57;
			float fTemp59 = fTemp58 + 1.2158854f;
			float fTemp60 = (fTemp58 + 0.5683306f) / fTemp57 + 0.70807946f;
			float fTemp61 = mydsp_faustpower2_f(fTemp57);
			float fTemp62 = 0.8224459f / fTemp61;
			float fTemp63 = fTemp62 + 0.014026448f;
			float fTemp64 = fTemp32 * std::max<float>(0.0f, std::min<float>(fTemp54, fSlow76 * fTemp55 + 1.0f));
			float fTemp65 = fSlow80 * fTemp64;
			float fTemp66 = std::max<float>(fTemp56 * (fSlow82 + fTemp65), 23.44895f);
			float fTemp67 = std::max<float>(2e+01f, std::fabs(fTemp66));
			float fTemp68 = fRec98[1] + fConst1 * fTemp67;
			fRec98[0] = fTemp68 - std::floor(fTemp68);
			float fTemp69 = mydsp_faustpower2_f(2.0f * fRec98[0] + -1.0f);
			fVec33[0] = fTemp69;
			float fTemp70 = float(iVec0[1]) * (fTemp69 - fVec33[1]) / fTemp67;
			fVec34[IOTA0 & 4095] = fTemp70;
			float fTemp71 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst10 / fTemp66));
			int iTemp72 = int(fTemp71);
			float fTemp73 = std::floor(fTemp71);
			float fTemp74 = fConst100 * (fTemp70 - fVec34[(IOTA0 - iTemp72) & 4095] * (fTemp73 + (1.0f - fTemp71)) - (fTemp71 - fTemp73) * fVec34[(IOTA0 - (iTemp72 + 1)) & 4095]) + fTemp65 + 1.1e+02f * fTemp56;
			float fTemp75 = fRec97[1] + fConst1 * (fSlow83 + fTemp74);
			fRec97[0] = fTemp75 - std::floor(fTemp75);
			float fTemp76 = fRec99[1] + fConst1 * (fSlow81 + fTemp74);
			fRec99[0] = fTemp76 - std::floor(fTemp76);
			fRec96[0] = fSlow84 * fTemp56 * (ftbl0mydspSIG0[int(65536.0f * fRec99[0])] + ftbl0mydspSIG0[int(65536.0f * fRec97[0])]) + fSlow79 * fTemp64 - (fRec96[2] * ((fTemp58 + -0.5683306f) / fTemp57 + 0.70807946f) + 2.0f * fRec96[1] * (0.70807946f - 1.0f / fTemp61)) / fTemp60;
			float fTemp77 = fRec96[0] * fTemp63 + 2.0f * fRec96[1] * (0.014026448f - fTemp62) + fRec96[2] * fTemp63;
			fVec35[0] = fTemp77 / fTemp60;
			fRec94[0] = fVec35[1] * (0.0f - 1.2158854f / (fTemp57 * fTemp59)) + (1.2158854f * (fTemp77 / (fTemp57 * fTemp60)) - fRec94[1] * (1.2158854f - fTemp58)) / fTemp59;
			float fTemp78 = std::max<float>(-1.0f, std::min<float>(1.0f, fSlow86 * fRec94[0]));
			float fTemp79 = fSlow23 * fTemp16 + fSlow87 * fTemp78 * (1.0f - 0.33333334f * mydsp_faustpower2_f(fTemp78)) + fSlow72 * fTemp43 + fSlow44 * fTemp31 + 0.5f * (fRec93[0] + fRec2[1] + fRec69[1] + fRec70 + fRec3);
			float fTemp80 = std::fabs(fTemp79);
			float fTemp81 = ((fTemp80 > fRec1[1]) ? fSlow89 : fConst101);
			fRec1[0] = fTemp80 * (1.0f - fTemp81) + fRec1[1] * fTemp81;
			fRec0[0] = fSlow91 * (0.0f - 0.6666667f * std::max<float>(fSlow90 + 2e+01f * std::log10(std::max<float>(1.1754944e-38f, fRec1[0])), 0.0f)) + fSlow3 * fRec0[1];
			float fTemp82 = fTemp79 * std::pow(1e+01f, 0.05f * fRec0[0]);
			output0[i0] = FAUSTFLOAT(fTemp82);
			output1[i0] = FAUSTFLOAT(fTemp82);
			iVec0[1] = iVec0[0];
			fRec11[1] = fRec11[0];
			fVec1[1] = fVec1[0];
			iRec14[1] = iRec14[0];
			fRec18[1] = fRec18[0];
			fRec15[1] = fRec15[0];
			fRec21[1] = fRec21[0];
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			fVec3[1] = fVec3[0];
			fRec19[1] = fRec19[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fVec4[1] = fVec4[0];
			iRec23[1] = iRec23[0];
			fRec30[1] = fRec30[0];
			fRec29[1] = fRec29[0];
			fRec28[1] = fRec28[0];
			fRec27[1] = fRec27[0];
			fRec33[1] = fRec33[0];
			fRec32[1] = fRec32[0];
			fRec31[1] = fRec31[0];
			fRec36[1] = fRec36[0];
			fRec35[1] = fRec35[0];
			fRec34[1] = fRec34[0];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			fRec37[1] = fRec37[0];
			fRec42[1] = fRec42[0];
			fRec41[1] = fRec41[0];
			fRec40[1] = fRec40[0];
			iRec43[1] = iRec43[0];
			fRec26[2] = fRec26[1];
			fRec26[1] = fRec26[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fVec5[1] = fVec5[0];
			fRec24[1] = fRec24[0];
			for (int j0 = 3; j0 > 0; j0 = j0 - 1) {
				fRec47[j0] = fRec47[j0 - 1];
			}
			fVec6[1] = fVec6[0];
			iRec48[1] = iRec48[0];
			fRec49[1] = fRec49[0];
			iRec50[1] = iRec50[0];
			fRec52[1] = fRec52[0];
			fRec51[1] = fRec51[0];
			fRec54[1] = fRec54[0];
			fRec53[1] = fRec53[0];
			fRec46[2] = fRec46[1];
			fRec46[1] = fRec46[0];
			fRec45[2] = fRec45[1];
			fRec45[1] = fRec45[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			IOTA0 = IOTA0 + 1;
			fRec10[1] = fRec10[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fRec58[1] = fRec58[0];
			fRec57[1] = fRec57[0];
			fRec60[1] = fRec60[0];
			fRec59[1] = fRec59[0];
			fRec62[1] = fRec62[0];
			fRec61[1] = fRec61[0];
			fRec64[1] = fRec64[0];
			fRec63[1] = fRec63[0];
			fRec66[1] = fRec66[0];
			fRec65[1] = fRec65[0];
			fRec68[1] = fRec68[0];
			fRec67[1] = fRec67[0];
			fRec8[1] = fRec8[0];
			fRec6[1] = fRec6[0];
			fRec4[1] = fRec4[0];
			fRec2[1] = fRec2[0];
			fRec78[1] = fRec78[0];
			fRec77[1] = fRec77[0];
			fRec80[1] = fRec80[0];
			fRec79[1] = fRec79[0];
			fRec82[1] = fRec82[0];
			fRec81[1] = fRec81[0];
			fRec84[1] = fRec84[0];
			fRec83[1] = fRec83[0];
			fRec86[1] = fRec86[0];
			fRec85[1] = fRec85[0];
			fRec88[1] = fRec88[0];
			fRec87[1] = fRec87[0];
			fRec90[1] = fRec90[0];
			fRec89[1] = fRec89[0];
			fRec92[1] = fRec92[0];
			fRec91[1] = fRec91[0];
			fRec75[1] = fRec75[0];
			fRec73[1] = fRec73[0];
			fRec71[1] = fRec71[0];
			fRec69[1] = fRec69[0];
			fRec93[1] = fRec93[0];
			fVec32[1] = fVec32[0];
			iRec95[1] = iRec95[0];
			fRec98[1] = fRec98[0];
			fVec33[1] = fVec33[0];
			fRec97[1] = fRec97[0];
			fRec99[1] = fRec99[0];
			fRec96[2] = fRec96[1];
			fRec96[1] = fRec96[0];
			fVec35[1] = fVec35[0];
			fRec94[1] = fRec94[0];
			fRec1[1] = fRec1[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
