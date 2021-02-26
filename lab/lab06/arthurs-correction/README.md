# Corrections by Arthur Gatin, Feb 26 2021

* ## Poems text files

The old `poems.zip` file contains the text files for the test cases on Gradescope had newlines at the end of the files, which caused a lot of confusion and failed test cases for the number of lines in the text file.

Many student solutions used the following logic in getting the lines:

```
ifstream ifs;
std::string newLine;
while( ! ifs.eof() ){
    getline(ifs, newLine);
    count++;
}
```
The issue here happens around the last line:

```
*last valid line of text in the poem*\n<EOF>
```
Because of the newline, getline() reads in the last line of text up until the `\n` character, and advances the file descriptor past the newline character. Note that is has not encountered the `<EOF>` character, so another iteration of the while loop will happen, when the newLine will be set to `""`, and only then getline() will encounter the `<EOF>` character.

**To address this issue, the text files have been edited to remove the newline at the end. Use the new archive `poems_noendl.zip`**

<br>

* ## Ambiguity

There is a fair amount of ambiguity in this lab, and these are the questions we need to decide on to create a better solution and improve the lab description that addresses these corner cases.

<br>

### 1. What constitutes a line that needs to be counted?

<br>

In the poem `TheTyger.txt`, which is one of the test cases and goes like this:

```
Tyger ! Tyger ! Burning bright
In the forests of the night,
What immortal hand or eye
Could frame thy fearful symmetry?

In what distant deeps or skies
Burnt the fire of thine eyes?
On what wings dare he aspire?
What the hand dare sieze the fire?

And what shoulder, & what art,
Could twist the sinews of thy heart?
And when thy heart began to beat,
What dread hand? & what dread feet?

What the hammer, what the chain?
In what furnace was thy brain?
What the anvil, what dread grasp
Dare its deadly terrors clasp?

When the stars threw down their spears,
And water'd heaven with their tears,
Did he smile his work to see?
Did he who made the Lamb make thee?

Tyger ! Tyger ! burning bright
In the forests of the night,
What immortal hand or eye
Dare frame thy fearful symmetry?
```

Are there 29 lines or 24?

The reference solution assumes that there are 29 lines of text in this poem.

This is one of the corner cases that needs to be reviewed, as there are at least 2 poems in the text files that include newlines between stanzas.

<br>

## 2. Rhymes between stanzas

Consider the following part of a poem, taken from the `ThoughtsInAGarden.txt`, which caused a lot of confusion:

```
Stumbling on melons, as I pass,
Ensnared with flowers, I fall on grass.

Meanwhile the mind from pleasure less
Withdraws into its happiness;
```

Surely, pass-grass is a rhyme, so it less-happiness.

But what about grass-less? According to the definition of a rhyme that we provide for this assignment (2 last letters of each line being the same), grass-less CAN be a rhyme if we don't count the empty line in between two stanzas to count as a valid line of text.

A bigger question is are there poems that are arranged in a way that the last line of a stanza rhymes with the first line of the new stanza? If so, we should count those as valid rhymes, but I would like to leave it to the discussion between professors to decide on such a corner case.



* ## `rhymesref.cpp`

I am including my solution as a candidate on the reference solution for the autograder. It counts newlines between stanzas and does not consider rhymes across stanzas.

I will be happy to update it to handle the corner cases I mentioned above differently. This solution was tested in W21 CS16 course offering taught by Zach Sisco.


<br>

*Prepared by Arthur Gatin*