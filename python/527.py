# 527. Word Abbreviation My SubmissionsBack To Contest
#
# Given an array of n distinct non-empty strings, you need to generate minimal possible abbreviations for every word following rules below.
#
# Begin with the first character and then the number of characters abbreviated, which followed by the last character.
# If there are any conflict, that is more than one words share the same abbreviation, a longer prefix is used instead of only the first character until making the map from word to abbreviation become unique. In other words, a final abbreviation cannot map to more than one original words.
# If the abbreviation doesn't make the word shorter, then keep it as original.
# Example:
# Input: ["like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"]
# Output: ["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]
# Note:
# Both n and the length of each word will not exceed 400.
# The length of each word is greater than 1.
# The words consist of lowercase English letters only.
# The return answers should be in the same order as the original array.
import re

class Solution(object):
    def wordsAbbreviation(self, dict):
        """
        :type dict: List[str]
        :rtype: List[str]
        """
        result = []
        conf = {}
        ld = len(dict)
        for i in xrange(ld):
            li = len(dict[i])
            if li <= 3:
                result.append(dict[i])
            else:
                t = dict[i][0]+str(li-2)+dict[i][-1]
                if not conf.has_key(t):
                    conf[t] = [i]
                    result.append(t)
                else:
                    diff = 0
                    for j in conf[t]:

                        for k in xrange(li):
                            if dict[j][k] != dict[i][k]:
                                break
                        if k > diff:
                            diff = k
                        if k > len(re.findall(r'[a-zA-Z]',result[j])) - 2:
                            if k < li - 3:
                                result[j] = dict[j][:k+1]+str(li-k-2)+dict[j][-1]
                            else:
                                result[j] = dict[j]
                    conf[t].append(i)
                    if diff < li - 3:
                        result.append(dict[i][:diff + 1] + str(li - diff - 2) + dict[i][-1])
                    else:
                        result.append(dict[i])
        return result

s = Solution()
print s.wordsAbbreviation(["bbadabadccdabdadccdd","aacbbbacccacaadabcdc","ccdcccdcbccadadbdcdd","abdbcaacbaacabccadaa","cbaaabddbbddcbbcbddb","addaadcdaabcccbddada","aaaabcbbcadabdaccdda","dbcabacdacdaaccdccdc","acdabbcdcabaaccdbbac","abbadcabdabcadcdccbc","ddbddbadacacacbcbaaa","dabaaababccaddbaacad","dbbdbcdcabbaacdccbdc","dcdcbbcccadbacdaddad","dacdbcdbaddabbbabbac","bdddacdcabbcccdbcdaa","abaababcccadabadbcdd","bbbccdbadcbaacadcacb","abddadccaaccccaacccd","dbbababacaacdbdbcdcb","cdadccadbdaaacbabbbc","adaaabbcabddadcacabb","bdbbbaadaddbbbddbabd","ddaccbdccadcaccabcbd","dbdacbbbacdbbddddbbd","bbaaadcccdbacdccdddd","cbdbbcddaacabcabbabd","bbacccdbdbddbabbbaba","cacabbaaaaaaabadbddc","daddaaccbadcacaadabc","adcdbddadabbdabcabdb","aabdacbdbacdddcbbbdc","bbcdbdbdcbacbccbbdaa","daadacbcbcbcddcdcbcc","daccabbdbddcddacbdcb","cbccacacabbcdbbcabac","bbdbcbbdbacabddbcbcb","acbbbcdbbdcddbccbbba","cbdabcdaccdbcddbbbcb","dabdbbcdcccdbdacbcca","cdccbdddbbdcadbcbcbd","cacccbccdcacdcbddcbd","bbcddabcdbcadcbcdaac","adddbcbdaacbabcddbcc","ccbbbbcaabccadbcdacd","cbbbbdaadaccdadccbad","caabaddbbacccaddcdcd","bbbcdbcddadabddcccbd","ccdadbcacdadbdbbacdb","cbcaddcadadcbcdabbdc","dcadcdbaabcacdddaaba","ccaadddcabdcbbdacdad","dacdadcbbbdddaabacaa","addbaddaabbddacbdbaa","adcabccccbaccdccadaa","cbaabdabdddcaaaabdac","dbcababcaaddbdacbdcc","bdaaaadcdbcacccccdac","baccadcdaabcbcdbabba","badccccddaabacdbcdac","dabcabbdadcdcadbcddb","abcdcbbaccdddadcaaba","aaaccabacbdbcadbabcb","ddbccbbbaccdabaacacb","bdacababadbadadbccbc","aacacadccabbcadbabac","bcbcddadaddbdbddddad","bcabddacadbaadcaddaa","ccdcbdcadacddaaacbab","ddcbdbabaddcacdadcaa","bcabddcdbbdabdbccbac","cbddcbccbcadacdaccbb","ddbcaddcdabccbbdcccd","cbadbbcacdccdddabadd","cdcbdcbddddcbccbadad","dcdacdbaacddbaaccaba","cccbddbbaddbcababcdb","dcbdbaddaabcdadcaaad","ddccbadacbdbcbccadcd","dcaccbddaccdabccbccb","bdcbddcbddcbbbbdabca","dcbddbbbacaacdacdbbc","abdbabbddbdacccbdbdd","cbaddbabdcbbbaadcdbb","dbacdbdcdcacaccbbabb","acdaccdababbbcdddbbd","badcccdabacadbdaabad","cdabbadbaccbadcbaacd","bdcaddbdccdcadaaabba","bccaaddbaabcbcacdcab","abaabacbcdcdbcadaacb","abbccddcbadaaaaadcdd","badbccdddbbbdcbdbddd","bcdbddcdcccbaabccbbd","bacabcdbcbabacdddddc","cbaabcbacdbcbdabcacb","ddbdadacadcaccbdbcdd","ccabbbbbdbcacbaacbbc","bccabcacdccccbdabcad","babbadcaddadabdbdcbc","ddcaacdcccbdbdadcaac","aacccddcbaddbacbaccc","adabadbcbdbcdaacbbdd","bbacaddcbaccbcbadcdb","badddadbddbbdbcaacda","aaccddddbddddaacbcaa","aabbcbdadcdcabcccadc","dacbdaabdccccbdddacd","dccbdddccdaacadbaabc","abacddbabdacacadbadc","abcbbddddbbdccacbabb","aacaacdaadcadaaccbcc","addbacdbcdabcadccdac","cbababbdccdbdbdacadb","babdbcbacdbadbadccaa","aaabcddbcdbacbdaabbd","dabcadaaabdbcaaacbbb","dcdcdacbcccbcabccdca","abbddccccdaaaabaccad","bcabbdacbcaaccdddddd","dacddcabcaddacbbbcaa","aabcbbbddabdbaabddbc","abcbdddbccbaaaaadcdb","cbabbdacdadaddbccaca","bcddbbdcdddbadbdbabc","bbdbdadbbbaccbadbdda","cccbbdbcadbbdccbdaaa","bbcbababbcdbadbaacda","adcdcddbcccbbbaaacdc","bbbdccdccdcdaacbdacb","bcbbacbccdadabddaada","dadadadaacaaccccbdac","abbbcddaaadbbcbcbdcd","dababccbbdadbadcaaad","bbcdccbdbdbbddcbacba","ccdaaababbbbdcaaabda","daaadaabaacaabdabbbd","abbbbbbcdbcddbacddcb","adddbdbbcbdbbcdaccca","ccbddabbdcdcaabbbdbb","dcddabddbaacbbbcbaca","bccaccadcabbaabaadaa","baadcbdcabcbbbcddccd","cbddcdcbddbccbaacabc","ddacabdbacbbabccadbd","daaddcadaccdbbdcdccd","abdaabcdbabbdbbcdcba","ccdbbcaabbdadbbdccdb","cadcddbbccadcdbdabcb","dcdcddbaabbddcbdaddb","cbcdbadcdcdaddcbcddd","ddadaadcbddadbbadccd","acdacaadcddbadbcdbdd","bbaadccddabcdadddbbb","caabadcbcdacdcbacbbd","badcbddccbdcdccbbbcd","aabcbddbdbcbacdaaada","abccdcbbacbbbacddcbd","cccbbbdabcbadcabaaab","acccbcbcbbbbaaddaccb","abdddbdaadcbcdcbbccc","abcdadacdcabdacddbdd","cdddcadadbddbcbbcdba","abdbadcacbcdaaabbacd","ccdaddabbacbbbcccaba","dddaacbddcbbbddacdbc","ddbbbdcdbddaaabcdaab","dbdabddacaadccaabbac","badddacadbdbacbddbcb","cdadcddaaacdaaaabdab","bccbadaccdbbdabddbab","ddaadabbddacacbdbcdb","addcbdbdbddbdaadcdaa","bbcabccadcdcbcdadcdd","bbaccccdbdacbcddacac","dbbaadabacabbbdcaddb","bcdbbaacbccaacdbaaaa","aaabcdadbaacbabdacbc","dbccbdacdbcbacdadaba","bdadcdcdbbcdcabdbbcc","cdbbbdaabddbccabdaac","baacabdccdcdccbcbdcc","bcbbbaaaddabdcddddcd","dcddacdddacccddacbdb","dcacdcbddccbbcaacbda","cbadbbbacabcddddcacc","dabbbdddbcddbccbabda","bbcacaaddbbabddbbdaa","cbaddabdabbcddadbaab","bbadcbbdbabddbabbcca","adbdcdddbabdaacdacab","bdaccaaddbaddbaabdcc","cbdcbacacdbbcbbccbbd","cdcabcccddbbcddccbdc","bddddcabbaabcbdbbabd","cdbcbabacacbcbcdbcbc","aadbacacbaadbbbcbdba","caadbbaddcddccbbabdb","aacbddbbbadddacdbdaa","bcadabdaadcacbcccbaa"])