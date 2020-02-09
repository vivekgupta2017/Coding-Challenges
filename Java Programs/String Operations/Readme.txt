Java String Operations

--------------------------------------------------------------------------------------------------------

Project Description 

Assignment Goal: Develop a program, using Java, to reverse the words constituting sentences in a file and also to calculate certain metrics.

●	An input file contains sentences. Each sentence contains words delimited by <space> character. Each sentence terminates with a period.
●	The words in each sentence should be reversed.
●	The sentences with the words reversed should be written to an output file.

Note: words in the input file are made of characters [a-zA-Z0-9] Note: The order of words in the sentence should not be changed - just each word should be reversed. Example A good student => A doog tneduts

Note: The order of sentences should not be changed. Instead, the words in each sentence need to be reversed (see input/output example for better understanding).

--------------------------------------------------------------------------------------------------------

METRICS
The following metrics should be calculated and written to a metrics file, the name of which provided via commandline.
●	AVG_NUM_WORDS_PER_SENTENCE - Average number of words per sentence. Round to 2 decimal places. Format: AVG_NUM_WORDS_PER_SENTENCE = <value>
●	AVG_NUM_CHARS_PER_SENTENCE - Average number of characters per sentence (including spaces, periods & excluding newline characters). Round to 2 decimal places. Format: AVG_NUM_CHARS_PER_SENTENCE = <value>
●	MAX_FREQ_WORD - Most used word in the file (max frequency). If there is contention between multiple words, then any one of them can be selected. Format: MAX_FREQ = <value>
●	LONGEST_WORD - Word with the most number of characters. If there is contention between multiple words, then any one of them can be selected. Format: LONGEST_WORD = <value>

--------------------------------------------------------------------------------------------------------

INPUT FORMAT 
Your program should accept three filenames from the command line - input.txt, putput.txt, and metrics.txt. Note that input.txt will be well formatted. 

--------------------------------------------------------------------------------------------------------

EXAMPLES 

input.txt
A new student has registered for design patterns in the spring of 2020. During the semester the students
are going to learn good design principles and design guidelines to be followed when developing applications.
All programming assignments are to be done in Java.

output.txt
A wen tneduts sah deretsiger rof ngised snrettap ni eth gnirps fo 0202. gniruD eth retsemes eth stneduts
era gniog ot nrael doog ngised selpicnirp dna ngised senilediug ot eb dewollof nehw gnipoleved snoitacilppa.
llA gnimmargorp stnemngissa era ot eb enod ni avaJ.

metrics.txt
AVG_NUMBER_WORDS_PER_SENTENCE = 14.33
AVG_NUM_CHARS_PER_SENTENCE = 88.33
MAX_FREQ_WORD = design
LONGEST_WORD = applications

--------------------------------------------------------------------------------------------------------