// Javascript code for CS trivia

// Question number and answer key for mcq questions
let MCQANSWER = ["RAM","IBM","MS excel"];
let MCQNUM = MCQANSWER.length;

// Answers for frq questions
let FRQANSWER = ["universalserialbus","macos"];
let FRQNUM = FRQANSWER.length;

// Run script when document is loaded
document.addEventListener('DOMContentLoaded', function() {

    // Array containing all the selected anwer buttons
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
        if (mcqAns.length != MCQNUM) {
            document.querySelector("#feedback1").innerHTML = "Answer all the questions first";
            setTimeout(function() {document.querySelector("#feedback1").innerHTML = "";}, 3000);
        }
        else {
            for (let i = 0; i < mcqAns.length; i++){
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

    let frqAns = document.querySelectorAll("input");
    let checkFrq = document.querySelector("#checkFrq");
    checkFrq.addEventListener("click", function() {
        let count = 0;

        for (let i = 0; i < frqAns.length; i++){
            if (FRQANSWER[i] === frqAns[i].value.toLowerCase().replace(/\s/g, "")){
                count++;
                frqAns[i].style.backgroundColor = "#90EE90";
            }
            else{
                frqAns[i].style.backgroundColor = "#ffcccb";
            }
        }

        let percent = Number((count / FRQNUM * 100).toPrecision(4));
        document.querySelector("#feedback2").innerHTML = percent + "%";
    })

})