pragma solidity ^0.5.0;
pragma experimental ABIEncoderV2;

contract HevrusaMeeting {
    struct Rating
    {
        int tokens; 
        int superTokens; 
    }

    struct Proposition
    {
        string propositions; 
        address proposer; 
        Rating rating; 
        uint numRaters; 
    }

    // //Personal - a period of time in the meeting participant takes to read/rate/write proposals of/to other participants. 
    // //Deliberation - a time spent between two participants to analyze proposals, discuss and make new. 
    // //Group - is when everyone meet together and play against the "Group wall". 
    // //Free - break time. 
    enum  MeetingCycleEnum {PERSONAL,DELIBERATION,GROUP,FREE} 

    struct MeetingConfig
    {
        MeetingCycleEnum[] type_policy; 
        uint[] time_poliy; 
        Rating tokens_per_user; 
        address[] users; 
    }

    struct Participant
    {
        address user_address;
        Rating tokens; 
        uint[] props_ids; 
    }

    // //list of propositions
    uint num_propositions; 
    uint num_ratings; 
    mapping(uint => Proposition) propositions;
    mapping(uint => Rating[]) participant_to_proprating; 

    Participant[] participants; 
    MeetingConfig config; 
    uint meeting_index; 
    uint[] participant_pairing; 

    constructor()  public
    {
        num_propositions = 0; 
        num_ratings = 0;
    }

    function AddProposition(string memory prop, address proposer, int token1, int token2) public 
    {
        num_propositions++; 
        propositions[num_propositions] = Proposition(prop, proposer, 
        Rating(token1, token2), 1);
    }

    //TODO
    //First time rating asign by use which never rated the proposition before
    function RateProposition(Rating memory r, address rater, Proposition memory p) public 
    {
        num_ratings++; 
    }

    //TODO
    //Change existing token allocation for a proposition. If 0 delete the rating. 
    function EditRatingProposition(string memory r, address rater, Proposition memory p) public 
    {

    }

    //TODO
    //Returns a list of prpopositions which are distributed randomly by their 
    //Popoularity - i.e. less popoular people still see but with lower probability.
    //Thus not so popular propositions will still be viewable and have a chance to raise. 
    function ShowWall(address participant) public returns (uint[] memory) 
    {
        return participant_pairing;
    }

    //Shows best propositions.
    //Higly rated, most discussed, most hated. 
    function ShowGroupWall() public returns (uint[] memory) 
    {
        return participant_pairing;
    }

    function StartMeeting() public 
    {
        for(uint i = 0; i < config.type_policy.length; i++)
        {    participants.push(Participant(
                config.users[i], 
                config.tokens_per_user, 
                new uint[](0)));

            participant_pairing.push(i);
        }
       
        meeting_index = 0;
    }

    function NextStageMeeting() public 
    {
        meeting_index++;
    }

    function RandomizePairing(uint[] memory random_numbers) public 
    {
        uint L = participants.length;

        for(uint i = 0; i < L; i++)
        {
            uint rand = random_numbers[i] % (L - i);
            uint val = participant_pairing[i];
            participant_pairing[i] = participant_pairing[i + rand];
            participant_pairing[i + rand] = val; 
        }
    }

    function FindMyPair(uint index) public returns (uint)  
    {
         uint L = participants.length;

        for(uint i = 0; i < L; i++)
        {
            if(participant_pairing[i] == index)
            {
                if(i % 2 == 0)
                    return participant_pairing[i + 1];
                else
                    return participant_pairing[i - 1];
            }
        }
    }
}