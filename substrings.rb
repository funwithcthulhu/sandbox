# Odin Project--Ruby Building Blocks--'project 3'
#
# Implement a method #substrings that takes a word as
# the first argument and then an array of valid substrings
# (your dictionary) as the second argument. It should return
# a hash listing each substring (case insensitive) that was
# found in the original string and how many times it was found.
#
# Example input:
# dict = ["below", "down", "go", "going", "horn", "how", "howdy",
#         "it", "i", "low", "own", "part", "partner", "sit"]
#
# string = "Howdy partner, sit down! How's it going?"
#
# Output: {"down"=>1, "go"=>1, "going"=>1, "how"=>2, "howdy"=>1,
#            "it"=>2, "i"=>3, "own"=>1, "part"=>1, "partner"=>1,
#           "sit"=>1}

def substrings(string, dictionary)
  cache = {}
  dictionary.each do |word|
    count = string.downcase.scan(word).size
    cache[word] = count if count > 0 
  end
  cache
end
