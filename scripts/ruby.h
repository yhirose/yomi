
#include <kytea/kytea.h>
#include <kytea/string-util.h>
#include <regex.h>

class Ruby
{
    public:
        Ruby(const std::string& model_path) {
            kytea_.readModel(model_path.c_str());
        }

        enum OutputType {
            Corpus = 0,
            HTML
        };

        std::string Process(const std::string& text, OutputType type) {
            kytea::StringUtil* util = kytea_.getStringUtil(); 
            const kytea::KyteaConfig* config = kytea_.getConfig();
            kytea::KyteaString surface_string = util->mapString(text);
            kytea::KyteaSentence sentence(surface_string, util->normalize(surface_string));
            kytea_.calculateWS(sentence);
            for (int i = 0; i < config->getNumTags(); i++) {
                kytea_.calculateTags(sentence, i);
            }
            std::string result;
            for (int i = 0; i < sentence.words.size(); i++) {
                const kytea::KyteaWord& w = sentence.words[i];
                const std::string& word = util->showString(w.surface);
                const std::string& yomi = util->showString(w.tags[0][0].first);
                if (yomi != "UNK") {
                    switch (type) {
                    case HTML:
                        result += "<ruby>" + word + "<rt>" + yomi + "</rt></ruby>";
                        break;
                    default:
                        result += "{" + word + "|" + yomi + "}";
                        break;
                    }
                } else {
                    result += word;
                }
            }
            return result;
        }

    private:
        kytea::Kytea kytea_;
};

// vim: et ts=4 sw=4 cin cino={1s ff=unix
