// Javascript code for CS trivia

// Question number and answer key for mcq questions
let MCQNUM = 3;
let MCQANSWER = ["RAM","IBM","MS excel"];

// Run script when document is loaded
document.addEventListener('DOMContentLoaded', function() {

    let mcqAns = [];
    let mcqAnsChoice = document.querySelectorAll("#mcq");

    // If MCQ answer choice is clicked
    for (let i = 0; i < mcqAnsChoice.length; i++){
        mcqAnsChoice[i].addEventListener('click', function() {

            mcqAnsChoice[i].style.borderColor = "blue";

            let sameNumQues = document.querySelectorAll("."+mcqAnsChoice[i].className);
            for (let j = 0; j < sameNumQues.length; j++){
                if (sameNumQues[j] != mcqAnsChoice[i]){
                    sameNumQues[j].style.borderColor = "";
                    sameNumQues[j].style.backgroundColor = "#d9edff";
                }
            }

            // Add selected answer choice to answer array
            mcqAns[mcqAnsChoice[i].className[1]-1] = mcqAnsChoice[i];
        })
    }

    // Check MCQ questions
    let checkMcq = document.querySelector("#checkMcq");
    checkMcq.addEventListener("click", function() {
        let count = 0;
        console.log(mcqAns.length);
        if (mcqAns.length != MCQNUM) {
            document.querySelector("#feedback1").innerHTML = "Answer all the questions first";
            setTimeout(function() {document.querySelector("#feedback1").innerHTML = "";}, 3000);
        }
        else {
            for (let i = 0; i < MCQNUM; i++){
                //count = MCQANSWER[i] === mcqAns[i].innerHTML.trim() ? count + 1:count;
                console.log(mcqAns[i]);
                if (MCQANSWER[i] === mcqAns[i].innerHTML.trim()){
                    count++;
                    mcqAns[i].style.backgroundColor = "#90EE90";
                }
                else{
                    mcqAns[i].style.backgroundColor = "#ffcccb";
                }
            }

            let percent = Number((count / MCQNUM * 100).toPrecision(4));
            document.querySelector("#feedback1").innerHTML = percent + "%";
        }
    })
})