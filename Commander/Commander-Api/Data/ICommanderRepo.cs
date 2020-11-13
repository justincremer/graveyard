using System.Collections.Generic;
using Commander.Models;
using Microsoft.AspNetCore.JsonPatch;

namespace Commander.Data
{
    public interface ICommanderRepo
    {
        bool SaveChanges();
        IEnumerable<Command> GetAllCommands();
        Command GetCommandById(int id);
        void PostCommand(Command c);
        void PutCommand(Command c);
        void PatchCommand(Command c);
        void DeleteCommand(Command c);
    }
}